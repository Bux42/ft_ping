/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:40:15 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:40:16 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"

int			valid_count(char *s)
{
	if (ft_strlen(s) > 2)
	{
		g_ping.max_count = ft_atoi(&s[2]);
		return (g_ping.max_count > 0);
	}
	return (0);
}

int			check_flag(char *s, int flag)
{
	if (s[1] == 'v')
		return (flag | VERBOSE_FLAG);
	if (s[1] == 'h')
		return (flag | HELP_FLAG);
	if (s[1] == 'a')
		return (flag | AUDIBLE_FLAG);
	if (s[1] == 'q')
		return (flag | QUIET_FLAG);
	if (s[1] == 'c' && valid_count(s))
		return (flag | COUNT_FLAG);
    return (-1);
}

int			valid_address()
{
	struct addrinfo	hints;
	int				ret;

	ft_bzero(&hints, sizeof(struct addrinfo));
	hints.ai_flags = AI_CANONNAME;
	hints.ai_family = AF_INET;

	if (begin_with("http://", g_ping.address))
		ret = getaddrinfo(&g_ping.address[7], NULL, &hints, &g_ping.addrinf);
	else
		ret = getaddrinfo(g_ping.address, NULL, &hints, &g_ping.addrinf);
	
	if (ret == 0)
		ret = 1;
	else
	{
		printf("./ft_ping : %s: %s\n", g_ping.address, g_ping.getaddr_err[ret + 11]);
		ret = 0;
	}
	return (ret);
}

int			valid_argv(char **s)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	while (s[++i])
	{
		if (ft_strlen(s[i]) > 1 && s[i][0] == '-')
		{
			if ((g_ping.options = check_flag(s[i], g_ping.options)) == -1)
			{
				printf("./ft_ping: invalid option -- '%s'\n", s[i]);
				return (0);
			}
		}
		else if (done == 0)
		{
			done = 1;
			g_ping.address = ft_strdup(s[i]);
		}
	}
	return (1);
}
