#include "../../inc/header.h"

int				begin_with(char *s1, char *s2)
{
	int i;

	i = -1;
	if (s1 && s2 && ft_strlen(s2) > ft_strlen(s1))
	{
		while (s1[++i])
			if (s1[i] != s2[i])
				return (0);
	}
	return (1);
}

void            ft_bzero(void* data, size_t len)
{
    size_t  i;

    i = 0;
    while (i < len)
    {
        ((char *)data)[i] = 0;
        i++;
    }
}

char            *ft_strdup(char *str)
{
    char    *ret;
    int     i;
    
    if (!ft_strlen(str))
        return (NULL);
    if (!(ret = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
        return (NULL);

    i = -1;
    while (str[++i])
        ret[i] = str[i];
    ret[i] = 0;
    return (ret);
}

char            *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int				ft_atoi(const char *str)
{
	int i;
	int neg;
	int nb;

	i = 0;
	neg = 0;
	nb = 0;
	while (str[i] == '\f' || str[i] == '\r' || str[i] == '\t' || str[i] == '\v'
	|| str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (neg)
		return (-nb);
	return (nb);
}