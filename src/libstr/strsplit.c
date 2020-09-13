/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:40:40 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:40:42 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/header.h"



int			count_words(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

char		*parse_word(const char *s, int i, int len)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	while (len--)
		ret[len] = s[--i];
	return (ret);
}

char		*get_word(const char *s, int pos, char c)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			len = 0;
			while (s[i] && s[i] != c)
			{
				len++;
				i++;
			}
			if (j == pos)
				ret = parse_word(s, i, len);
			j++;
		}
		if (s[i])
			i++;
	}
	return (ret);
}

char            **ft_strsplit(char *s, char c)
{
    char    **ret;
    int     len;
    int     i;

    len = 0;
    ret = NULL;

    len = count_words(s, c);
    if (!len)
        return (NULL);
    if (!(ret = (char**)malloc(sizeof(char*) * (len + 1))))
        return (NULL);
    ret[len] = NULL;
    i = 0;
	while (i < len)
	{
		ret[i] = get_word(s, i, c);
		i++;
	}
    return (ret);
}
