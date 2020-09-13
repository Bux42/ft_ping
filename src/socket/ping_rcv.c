/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping_rcv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:41:18 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:41:19 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void reverse_dns_lookup(uint32_t ip_addr)
{
	struct sockaddr_in temp_addr;
	socklen_t len;

	temp_addr.sin_family = AF_INET;
	temp_addr.sin_addr.s_addr = ip_addr;
	len = sizeof(struct sockaddr_in);

	if (getnameinfo((struct sockaddr *)&temp_addr, len, g_ping.reverse_dns,
					NI_MAXHOST, NULL, 0, NI_NOFQDN) != 0)
		ft_strcpy(g_ping.reverse_dns, g_ping.socket->address);
}

void print_ack_message(ssize_t ret, struct iphdr *ip_header,
					   struct icmphdr *icmp_header, struct timeval *timeval_msg)
{
	double elapsed_time;
	struct timeval timeval_now;

	gettimeofday(&timeval_now, NULL);
	if (g_ping.reverse_dns[0] == '\0')
	{
		inet_ntop(AF_INET, &ip_header->saddr, g_ping.host_addr,
									 INET_ADDRSTRLEN);
		reverse_dns_lookup(ip_header->saddr);
	}
	elapsed_time = (timeval_now.tv_usec - timeval_msg->tv_usec) / 1000.0f;
	elapsed_time += (timeval_now.tv_sec - timeval_msg->tv_sec) * 1000;
	if (g_ping.options & AUDIBLE_FLAG)
		printf("\a");
	printf("%zd bytes from %s (%s): icmp_seq=%hu ttl=%u ", ret - sizeof(struct iphdr),
		   g_ping.reverse_dns, g_ping.socket->address,
		   icmp_header->un.echo.sequence, ip_header->ttl);
	if (elapsed_time > 100.f)
		printf("time=%zd ms\n", (ssize_t)elapsed_time);
	else
		printf("time=%#.3g ms\n", elapsed_time);
}

int check_response(char *buffer, ssize_t ret)
{
	struct iphdr *ip_header;
	struct icmphdr *icmp_header;
	struct timeval *timeval_msg;

	ip_header = (struct iphdr *)buffer;
	icmp_header = (struct icmphdr *)(buffer + sizeof(struct iphdr));
	timeval_msg = (struct timeval *)(buffer + sizeof(struct iphdr) + sizeof(struct icmphdr));
	if (icmp_header->un.echo.id == g_ping.id && icmp_header->un.echo.sequence == g_ping.sequence)
	{
		if ((g_ping.options & QUIET_FLAG) == 0)
			print_ack_message(ret, ip_header, icmp_header, timeval_msg);
		g_ping.nb_received_packets += 1;
		return (1);
	}
	else
	{
		return (0);
	}
}

void get_response(void)
{

	char buffer[548];
	struct sockaddr copy;
	struct iovec iov;
	struct msghdr message;
	ssize_t ret;

	iov.iov_base = buffer;
	iov.iov_len = sizeof(buffer);
	message.msg_name = &copy;
	message.msg_namelen = sizeof(struct sockaddr);
	message.msg_iov = &iov;
	message.msg_iovlen = 1;
	message.msg_control = 0;
	message.msg_controllen = 0;
	ret = recvmsg(g_ping.socket->sockfd, &message, 0);
	if (ret > 0 && check_response(buffer, ret) == 0)
		get_response();
	if (g_ping.options & COUNT_FLAG && (int)g_ping.nb_sent_packets == g_ping.max_count)
		ping_interupt(1);
}
