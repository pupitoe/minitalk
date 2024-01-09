/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:33:33 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 20:21:10 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "../commun/commun.h"

void	ft_client_handler(int signal, siginfo_t *info, void *context);
int		ft_call_server(pid_t server);

int		ft_push_len(char *str, pid_t pid);
int		ft_socket_string(char *str, pid_t pid);
int		ft_socket_car(char c, pid_t pid);

extern pid_t	g_pid_server;

#endif