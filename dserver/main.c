/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:02:12 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/04 13:23:17 by tlassere         ###   ########.fr       */
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
	static int		i = 0;
	static size_t	size = 0;
	static char		*buffer = NULL;

	if (i == 0)
	{
		size++;
		if (ft_add_car(&buffer, 0, size) == -1)
			return (-1);
	}
	if (signal == SIGUSR1)
		buffer[size - 1] = buffer[size - 1] | 1 << i % 8;
	if (++i == 8)
		i = 0;
	if (buffer[size - 1] == '\0' && i == 0)
		ft_putstr(buffer);
	if ((buffer[size - 1] == '\0' && i == 0) || delet)
	{
		free(buffer);
		buffer = NULL;
		size = 0;
		i = 0;
	}
	return (0);
}

static void	ft_get_signal(int signal, siginfo_t *info, void *ucontext)
{
	static pid_t	client_pid = -1;

	if (client_pid == -1)
		client_pid = info->si_pid;
	else if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		if (ft_rep_signal(0, 1) == -1)
			exit(1);
	}
	if (ft_rep_signal(signal, 0) == -1)
		exit(1);
	ucontext++;
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
		;
	return (0);
}
