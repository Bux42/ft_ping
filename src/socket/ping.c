/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ping.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:41:12 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:41:13 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"


void		ping(int sig)
{
	t_packet	packet;

	packet = create_packet();
	(void)sig;
	g_ping.nb_sent_packets++;
	sendto(g_ping.socket->sockfd, &packet, sizeof(packet), 0,
				g_ping.addrinf->ai_addr, sizeof(struct sockaddr_in));
	alarm(1);
	get_response();
}

void		ping_interupt(int inp)
{
	float			loss;
	struct timeval	timeval_now;
	double			timediff;

	(void)inp;
	gettimeofday(&timeval_now, NULL);
	timediff = (timeval_now.tv_usec - g_ping.start_time.tv_usec) / 1000.0f;
	timediff += (timeval_now.tv_sec - g_ping.start_time.tv_sec) * 1000;
	loss = ((float)g_ping.nb_received_packets / (float)g_ping.nb_sent_packets);
	loss = 100 - loss * (float)100;
	printf("\n--- %s ping statistics ---\n", g_ping.address);
	printf("%ld packets transmitted, %ld received, %ld%c packet loss, time %d%s\n", 
		g_ping.nb_sent_packets, g_ping.nb_received_packets, (size_t)loss, '%', (int)timediff, "ms");
	close(g_ping.socket->sockfd);
	exit(1);
}

void		init_ping(void)
{
	signal(SIGALRM, ping);
	signal(SIGINT, &ping_interupt);
	gettimeofday(&g_ping.start_time, NULL);
	ping(0);
	while (1)
		;
}
