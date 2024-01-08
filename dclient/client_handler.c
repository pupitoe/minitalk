/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:32:42 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/08 23:24:02 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern pid_t	g_pid_server;
void	ft_client_handler(int signal, siginfo_t *info, void *context)
{
	if (info->si_pid != g_pid_server)
	{
		ft_putstr("Another prossesuce sent a signal\n");
		return ;
	}
	if (signal != SIGUSR1)
		return ;
	ft_putstr("Get reception\n");
	(void)context;
	return ;
}
