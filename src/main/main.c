#include "../../inc/header.h"

int print_verbose()
{
    printf("Usage: ping [-hv]\n");
    return (0);
}

int main(int ac, char **av)
{
    getaddrinfo_error();
    if (ac > 1 && init_socket(&g_ping) && valid_argv(av))
    {
        if (g_ping.options & HELP_FLAG)
            return (print_verbose());
        if (valid_address(g_ping.socket->address) && init_setsockopt())
            init_ping();
    }
	else if (ac == 1)
		return (print_verbose());
    return (0);
}