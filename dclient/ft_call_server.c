/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:32:56 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 20:22:28 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_call_server(pid_t server)
{
	if (kill(server, SIGUSR1) == -1)
		return (-1);
	pause();
	return (0);
}

int	ft_socket_car(char c, pid_t pid)
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

int	ft_socket_string(char *str, pid_t pid)
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

int	ft_push_len(char *str, pid_t pid)
{
	size_t	len;
	int		buffer;
	size_t	i;

	len = ft_strlen(str);
	i = 0;
	while (i < sizeof(size_t) * 8)
	{
		if ((len & (1 << i)) != 0)
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
