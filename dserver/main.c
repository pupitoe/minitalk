/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:02:12 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/06 17:54:33 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_free_instruction = -1;

static pid_t	ft_print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("Server pid : ");
	if (ft_print_nbr(pid) == -1)
		exit(-12);
	ft_putcar('\n');
	return (pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_print_pid();
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_get_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sleep(5);
		if (g_free_instruction == 0)
		{
			g_free_instruction--;
			ft_rep_signal(0, 1);
		}
		if (g_free_instruction > 0)
			g_free_instruction--;
	}
	return (0);
}
