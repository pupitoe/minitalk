/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:02:12 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 17:50:44 by tlassere         ###   ########.fr       */
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
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		return (1);
	while (1)
	{
		sleep(5);
		if (g_free_instruction == 0)
		{
			g_free_instruction--;
			ft_use_sigal(0, 0, 1);
			ft_use_sigal(SIGUSR1, -1, 0);
		}
		if (g_free_instruction > 0)
			g_free_instruction--;
	}
	return (0);
}
