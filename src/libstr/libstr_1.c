#include "../../inc/header.h"

size_t          ft_stra_isnum(char **s, size_t maxlen)
{
    int     i;
    int     j;

    i = -1;
    while (s[++i])
    {
        if (ft_strlen(s[i]) > 0 && ft_strlen(s[i]) <= maxlen)
        {
            j = -1;
            while (s[i][++j])
                if (s[i][j] < 48 || s[i][j] > 57)
                    return (0);
        }
        else
            return (0);
    }
    return (1);
}

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
