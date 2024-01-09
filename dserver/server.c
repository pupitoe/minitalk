/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:08 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 01:04:52 by tlassere         ###   ########.fr       */
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
	}
	return (0);
}

int	ft_current_client(t_client *client, int signal)
{
	g_free_instruction = 3;
	if (client->action == 0)
	{
		client->action++;
		if (kill(client->client_pid, SIGUSR1) == -1)
			return (-1);
		return (0);
	}
	if (client->action == 1)
	{
		if (ft_rep_signal(signal, 0) == MALLOC_FAIL)
			return (MALLOC_FAIL);
	}
	return (0);
}

int	ft_use_sigal(int signal, siginfo_t *info, int del_queue)
{
	static t_list	*queue = NULL;
	int				buffer = 0;

	if (del_queue)
		return (ft_delete_queue(&queue), ft_rep_signal(0, 1), 0);
	if (ft_queue(info->si_pid, &queue) == MALLOC_FAIL)
		return (ft_lstclear(&queue, &free), ft_rep_signal(0, 1), exit(-12), 0);
	if (info->si_pid != ((t_client *)queue->content)->client_pid)
		return (0);
	buffer = ft_current_client(queue->content, signal);
	if (buffer == FULL_STR)
		g_free_instruction = -1;
	if (buffer == -1 || buffer == FULL_STR)
		ft_delete_queue(&queue);
	if (buffer == MALLOC_FAIL)
		return (ft_lstclear(&queue, &free), ft_rep_signal(0, 1), exit(-12), 0);
	return (0);
}

void	ft_get_signal(int signal, siginfo_t *info, void *ucontext)
{
	ft_use_sigal(signal, info, 0);
	(void)ucontext;
}
