/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:32:42 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/06 19:13:14 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	ft_client_handler(int signal, siginfo_t *info, void *context)
{
	if (signal != SIGUSR1)
		return ;	
	if (info->si_pid != g_pid_server)
	{
		ft_putstr("Another prossesuce sent a signal\n");
		return ;
	}
	ft_putstr("Get packet\n");
	(void)context;
	return ;
}
