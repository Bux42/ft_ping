#include "../../inc/header.h"

size_t          ft_stralen(char **s)
{
    size_t  ret = 0;

    if (*s)
        while (s[ret])
            ret++;

    return (ret);
}

size_t          ft_strlen(char *s)
{
    size_t  ret = 0;

    if (s)
        while (s[ret])
            ret++;

    return (ret);
}

size_t          char_count_str(char *s, char c)
{
    size_t ret;
    size_t i;

    ret = 0;
    i = 0;

    if (!s)
        return (0);

    while (s[i])
    {
        if (s[i] == c)
        {
            ret++;
        }
        i++;
    }
    return (ret);
}
