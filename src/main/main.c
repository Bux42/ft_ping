/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:40:07 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:40:08 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int		print_verbose(void)
{
	printf("Usage: ping [-hvcqa]\n");
	return (0);
}

void	debug_flags()
{
	printf("OPTIONS: %d\n", g_ping.options);
	printf("VERBOSE_FLAG: %d\n", g_ping.options & VERBOSE_FLAG);
	printf("AUDIBLE_FLAG: %d\n", g_ping.options & AUDIBLE_FLAG);
	printf("QUIET_FLAG: %d\n", g_ping.options & QUIET_FLAG);
	printf("HELP_FLAG: %d\n", g_ping.options & HELP_FLAG);
	printf("COUNT_FLAG: %d\n", g_ping.options & COUNT_FLAG);
	printf("%d\n", g_ping.max_count);
}

int		main(int ac, char **av)
{
	getaddrinfo_error();
	if (ac > 1 && valid_argv(av))
	{
		if (g_ping.options & HELP_FLAG || g_ping.address == NULL)
			return (print_verbose());
		if (valid_address(g_ping.address) && init_socket(&g_ping) && init_setsockopt())
			init_ping();
	}
	else if (ac == 1)
		return (print_verbose());
	return (0);
}
