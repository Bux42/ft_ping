/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_packet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:41:03 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:41:03 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

t_packet		create_packet(void)
{
	t_packet	packet;

	ft_bzero(&packet, sizeof(packet));
	packet.header.type = ICMP_ECHO;
	packet.header.un.echo.id = g_ping.id;
	packet.header.un.echo.sequence = ++g_ping.sequence;

	gettimeofday((struct timeval *)(packet.data), NULL);
	packet.header.checksum = checksum((uint16_t *)&packet, sizeof(packet));

	return (packet);
}
