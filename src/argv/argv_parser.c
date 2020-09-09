#include "../../inc/header.h"

int         hostname(char *s)
{
    if (!s)
        return (0);
    return (0);
}

int         ipv4(char *s)
{
    char **ip;

    if ((ip = ft_strsplit(s, '.')) && ft_stralen(ip) == 4)
    {
        printf("%ld stralen:\n", ft_stralen(ip));
        int i = 0;
        while (ip[i])
        {
            printf("%s\n", ip[i]);
            i++;
        }
    }
    return (0);
}

int         valid_argv(char *s)
{
    if (s)
    {
        if (ipv4(s))
            return (1);
        else if (hostname(s))
            return (1);
    }
    return (0);
}