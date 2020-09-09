#ifndef HEADER_H

#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

typedef struct          s_socket
{
    int                 sockfd;
}                       t_socket;

int                     valid_argv(char *s);
int                     ipv4(char *s);
int                     hostname(char *s);

size_t                  char_count_str(char *s, char c);
size_t                  ft_strlen(char *s);
size_t                  ft_stralen(char **s);
char                    **ft_strsplit(char *s, char c);

#endif