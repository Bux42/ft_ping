#include "../../inc/header.h"

int main(int ac, char **av)
{
    if (av && ac == 2 && valid_argv(av[1]))
    {
        printf("%s\n", av[1]);
    }
    
    t_socket *socket;

    if (!(socket = (t_socket*)malloc(sizeof(t_socket))))
    {
        
    }
    struct timeval tv;
    struct timezone tz;

    if (gettimeofday(&tv, &tz) == 0)
    {
        printf("%ld.%06ld\n", tv.tv_sec, tv.tv_usec);
    }

    
    return (0);
}