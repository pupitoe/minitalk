/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:08 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 01:25:59 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_rep_signal(int signal, int delet)
{
	static int		i = 0;
	static size_t	size = 0;
	static char		*buffer = NULL;

	if (delet == 0 && i == 0)
	{
		size++;
		if (ft_add_car(&buffer, 0, size) == -1)
			return (-1);
	}
	if (delet == 0 && signal == SIGUSR1)
		buffer[size - 1] = buffer[size - 1] | 1 << i % 8;
	if (delet == 0 && ++i == 8)
		i = 0;
	if (delet == 0 && buffer[size - 1] == '\0' && i == 0)
		ft_putstr(buffer);
	if (delet || (buffer[size - 1] == '\0' && i == 0))
	{
		free(buffer);
		buffer = NULL;
		size = 0;
		i = 0;
		return (FULL_STR);
	}
	return (0);
}

int	ft_current_client(t_client *client, int signal)
{
	int	buffer;

	g_free_instruction = 3;
	buffer = 0;
	if (client->action == 0)
	{
		client->action += 1;
		if (kill(client->client_pid, SIGUSR1) == -1)
			buffer = -1;
	}
	else if (client->action == 1)
		buffer = ft_rep_signal(signal, 0);
	return (buffer);
}

int	ft_use_sigal(int signal, pid_t c_client, int del_queue)
{
	static t_list	*queue = NULL;
	int				buffer = 0;

	if (del_queue)
		return (ft_delete_queue(&queue), ft_rep_signal(0, 1), 0);
	if (c_client == -1)
	{
		if (queue == NULL)
			return (0);
		c_client = ((t_client *)queue->content)->client_pid;
	}
	if (ft_queue(c_client, &queue) == MALLOC_FAIL)
		return (ft_lstclear(&queue, &free), ft_rep_signal(0, 1), exit(-12), 0);
	if (c_client != ((t_client *)queue->content)->client_pid)
		return (0);
	buffer = ft_current_client(queue->content, signal);
	if (buffer == -1 || buffer == FULL_STR)
		ft_delete_queue(&queue);
	if (buffer == MALLOC_FAIL)
		return (ft_lstclear(&queue, &free), ft_rep_signal(0, 1), exit(-12), 0);
	if (buffer == FULL_STR)
	{
		g_free_instruction = -1;
		if (queue != NULL)
			ft_use_sigal(1, ((t_client *)queue->content)->client_pid, 0);
	}
	return (0);
}

void	ft_get_signal(int signal, siginfo_t *info, void *ucontext)
{
	ft_use_sigal(signal, info->si_pid, 0);
	(void)ucontext;
}
