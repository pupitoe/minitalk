/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:09:39 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 01:46:48 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	g_pid_server = 0;

static int	ft_parser(char *str)
{
	size_t	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '+'))
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_atoi_over(char *str)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		res = res * 10 + str[i] - '0';
		if (res % 10 != str[i] - '0')
			return (-1);
		i++;
	}
	return (res);
}

static int	ft_socket_car(char c, pid_t pid)
{
	int	i;
	int	buffer;

	i = 0;
	buffer = 0;
	while (i < 8)
	{
		if ((c & (1 << i)) != 0)
			buffer = kill(pid, SIGUSR1);
		else
			buffer = kill(pid, SIGUSR2);
		if (buffer == -1)
			return (-1);
		pause();
		i++;
	}
	return (0);
}

static int	ft_socket_string(char *str, pid_t pid)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_socket_car(str[i], pid))
			return (-1);
		i++;
	}
	if (ft_socket_car(0, pid))
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
		return (ft_putstr("Invalid arguments\n"));
	if (ft_parser(argv[1]) == -1)
		return (ft_putstr("The first argument is not the PID\n"));
	pid = ft_atoi_over(argv[1]);
	if (pid == -1)
		return (ft_putstr("PID overflow\n"));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_client_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		return (ft_putstr("SIGACTION fails\n"));
	g_pid_server = pid;
	if (ft_call_server(pid) == -1)
		return (ft_putstr("Signal transmission error\n"));
	if (ft_socket_string(argv[2], pid) == -1)
		return (ft_putstr("Signal transmission error\n"));
	return (0);
}
