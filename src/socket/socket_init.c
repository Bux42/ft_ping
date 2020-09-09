#include "../../inc/header.h"

t_socket        *socket_init()
{
    t_socket    *ret;

    if (!(ret = (t_socket*)malloc(sizeof(t_socket))))
        return (NULL);

    ret->s_family = AF_INET;
    ret->s_type = SOCK_RAW;
    ret->s_protocol = 0;

    return (ret);
}