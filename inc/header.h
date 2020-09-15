/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <videsvau@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:39:58 by videsvau          #+#    #+#             */
/*   Updated: 2020/09/13 14:40:01 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H

# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/time.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <unistd.h>
# include <netdb.h>
# include <signal.h>
# include <arpa/inet.h>
# ifndef EAI_NODATA
# define EAI_NODATA -5
# endif
# define VERBOSE_FLAG 1
# define AUDIBLE_FLAG 2
# define QUIET_FLAG 4
# define HELP_FLAG 8
# define COUNT_FLAG 16

typedef struct			s_packet
{
	struct icmphdr		header;
	char				data[56L];
}						t_packet;

typedef struct			s_socket
{
	int					sockfd;
	int					s_family;
	int					s_type;
	int					s_protocol;
	struct sockaddr_in	sock_addr_in;
}						t_socket;

typedef struct			s_ping
{
	int					flags;
	struct s_socket		*socket;
	char				*address;
	uint16_t			id;
	uint16_t			sequence;
	uint32_t			ttl;
	struct addrinfo		*addrinf;
	size_t				nb_received_packets;
	size_t				nb_sent_packets;
	int					max_count;
	struct timeval		start_time;
	char				reverse_dns[NI_MAXHOST];
	char				host_addr[INET_ADDRSTRLEN];
	int					options;
	char				getaddr_err[11][50];
}						t_ping;

int						print_verbose();

void					debug_flags();
int						valid_argv(char **s);
int						valid_address();

int						begin_with(char *s1, char *s2);
char					*ft_strdup(char *str);
void					ft_bzero(void *data, size_t len);
size_t					char_count_str(char *s, char c);
size_t					ft_strlen(char *s);
size_t					ft_stralen(char **s);
char					**ft_strsplit(char *s, char c);
size_t					ft_stra_isnum(char **s, size_t maxlen);
char					*ft_strcpy(char *dest, char *src);
int						ft_atoi(const char *str);

int						init_socket();
int						init_setsockopt();

uint16_t				checksum(uint16_t *buffer, size_t len);

void					getaddrinfo_error();

t_packet				create_packet();
void					init_ping();
void					ping();
void					ping_interupt(int inp);
void					get_response(void);
int						check_response(char *buffer, ssize_t ret);
void					print_ack_message(ssize_t ret, struct iphdr *ip_header,
							struct icmphdr *icmp_h, struct timeval *time_msg);
void					reverse_dns_lookup(uint32_t ip_addr);

t_ping					g_ping;

#endif
