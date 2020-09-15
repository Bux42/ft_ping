/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:41:38 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:41:39 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int		init_socket(void)
{
	if (!(g_ping.socket = (t_socket *)malloc(sizeof(t_socket))))
		return (0);

	if ((g_ping.socket->sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) > 0)
	{
		g_ping.id = (uint16_t)getpid();
		g_ping.ttl = 64;
		g_ping.socket->sock_addr_in.sin_addr.s_addr = INADDR_ANY;
		g_ping.socket->sock_addr_in.sin_port = htons(0);
		g_ping.socket->sock_addr_in.sin_family = AF_INET;
	}
	else
	{
		printf("socket: Operation not permitted\n");
		return (0);
	}
	return (1);
}

int		init_setsockopt(void)
{
	struct timeval	timeout;

	if (setsockopt(g_ping.socket->sockfd, SOL_IP, IP_TTL, &g_ping.ttl,
		sizeof(g_ping.ttl)) != 0)
	{
		close(g_ping.socket->sockfd);
		return (0);
	}
	timeout.tv_sec = 1;
	timeout.tv_usec = 10000;
	if (setsockopt(g_ping.socket->sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout,
		sizeof(timeout)) != 0)
	{
		close(g_ping.socket->sockfd);
		return (0);
	}
	return (1);
}
