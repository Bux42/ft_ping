/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getaddrinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:40:29 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:40:30 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

void		getaddrinfo_error()
{
	ft_bzero(g_ping.getaddr_err[EAI_AGAIN + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_AGAIN + 11], "Temporary failure in name resolution");
	ft_bzero(g_ping.getaddr_err[EAI_BADFLAGS + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_BADFLAGS + 11], "Bad value for ai_flags");
	ft_bzero(g_ping.getaddr_err[EAI_FAIL + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_FAIL + 11], "Non-recoverable failure in name resolution");
	ft_bzero(g_ping.getaddr_err[EAI_FAMILY + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_FAMILY + 11], "ai_family not supported");
	ft_bzero(g_ping.getaddr_err[EAI_MEMORY + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_MEMORY + 11], "Memory allocation failure");
	ft_bzero(g_ping.getaddr_err[EAI_NONAME + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_NONAME + 11], "Name or service not known");
	ft_bzero(g_ping.getaddr_err[EAI_SERVICE + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_SERVICE + 11], "Servname not supported for ai_socktype");
	ft_bzero(g_ping.getaddr_err[EAI_SOCKTYPE + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_SOCKTYPE + 11], "ai_socktype not supported");
	ft_bzero(g_ping.getaddr_err[EAI_SYSTEM + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_SYSTEM + 11], "System error");
	ft_bzero(g_ping.getaddr_err[EAI_NODATA + 11], 50);
	ft_strcpy(g_ping.getaddr_err[EAI_NODATA + 11], "No address associated with hostname");
}
