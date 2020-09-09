#include "../../inc/header.h"

int         hostname(char *s)
{
    if (!s)
        return (0);
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