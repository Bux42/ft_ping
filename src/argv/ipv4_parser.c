#include "../../inc/header.h"

int         ipv4(char *s)
{
    char **ip;
    
    if ((ip = ft_strsplit(s, '.')) && ft_stralen(ip) == 4)
    {
        if (ft_stra_isnum(ip, 3))
            return (1);
    }
    return (0);
}