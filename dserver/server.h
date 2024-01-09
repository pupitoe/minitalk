/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:24 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 20:18:50 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "../commun/commun.h"
# define FULL_STR 4
# define FINISH_PACKET 69
# define NO_ACTION 0
# define PUSH_FIRST_PACKET 1
# define GET_FULL_SIZE 5
# define REP_SIZE 2
# define REP_STR 3

typedef struct s_client
{
	pid_t	client_pid;
	int		action;
	char	*curent_str;
	size_t	size;
	size_t	index;
	int		c_bit;
	char	c_buffer;
}				t_client;

int		ft_queue(pid_t client, t_list **queue);
void	ft_delete_queue(t_list **queue);
int		ft_check_content(t_list *lst, pid_t client);
t_list	*ft_creat_el(pid_t client);
void	ft_free_queue(void *cur_client);

void	ft_get_signal(int signal, siginfo_t *info, void *ucontext);
int		ft_rep_signal(int signal, t_client *client);
int		ft_use_sigal(int signal, pid_t c_client, int del_queue);
int		ft_tcp_client(pid_t pid);

extern int	g_free_instruction;

#endif