/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:33:33 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/08 23:23:55 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H
# include "../commun/commun.h"

void	ft_client_handler(int signal, siginfo_t *info, void *context);
int		ft_call_server(pid_t server);

//extern pid_t	g_pid_server;

#endif