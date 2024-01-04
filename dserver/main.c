/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:02:12 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/04 01:13:59 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../commun/commun.h"

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

static int	ft_rep_signal(int signal, int delet)
{
	static size_t	i = 0;
	static char		c = 0;
	static char		*buffer = NULL;

	if (delet)
		return (free(buffer), 0);
	if (signal == SIGUSR1)
		c = c | 1 << i % 8;
	i++;
	if (i % 8 == 0)
	{
		if (ft_add_car(&buffer, c, i / 8) == -1)
			return (-1);
		if (buffer[i / 8] == '\0')
		{
			ft_putstr(buffer);
			free(buffer);
			buffer = NULL;
			i = 0;
		}
		c = 0;
	}
	return (0);
}


#include <stdio.h>

static void	ft_get_signal(int signal, siginfo_t *info, void *ucontext)
{
	ucontext++;
	
	//ft_print_nbr((int)info->si_pid);
	//ft_putcar('\n');
	//printf("%d\n", info->si_pid);
	info++;

	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		if (ft_rep_signal(signal, 0) == -1)
			exit(1);
	}
	else
		exit(0);
}

int	main(void)
{
	struct sigaction sa;
	ft_print_pid();
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_flags = SA_SIGINFO; // rechercher sont utiliter dans le man uwu je suis un gros debile ui car je cherche pas se qu'il faut comme un connard xoxo;
	sa.sa_sigaction = &ft_get_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		;
	return (0);
}
