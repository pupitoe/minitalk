/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:08 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 15:28:44 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_rep_signal(int signal, t_client *client)
{
	if (client->c_bite == 0)
	{
		client->size += 1;
		if (ft_add_car(&(client->curent_str), 0, client->size) == -1)
			return (MALLOC_FAIL);
	}
	if (signal == SIGUSR1)
		client->curent_str[client->size - 1] |= 1 << client->c_bite;
	if (++(client->c_bite) == 8)
		client->c_bite = 0;
	if (client->curent_str[client->size - 1] == '\0' && client->c_bite == 0)
	{
		ft_putstr(client->curent_str);
		return (FULL_STR);
	}
	return (FINISH_PACKET);
}

int	ft_tcp_client(pid_t pid)
{
	usleep(100);
	if (kill(pid, SIGUSR1) == -1)
		return (-1);
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
		buffer = ft_tcp_client(client->client_pid);
	}
	else if (client->action == 1)
		buffer = ft_rep_signal(signal, client);
	if (buffer == FINISH_PACKET)
		buffer = ft_tcp_client(client->client_pid);
	else if (buffer == FULL_STR)
	{
		ft_tcp_client(client->client_pid);
		g_free_instruction = -1;
	}
	return (buffer);
}

int	ft_use_sigal(int signal, pid_t c_client, int del_queue)
{
	static t_list	*queue = NULL;
	int				buffer;

	buffer = 0;
	if (del_queue)
		return (ft_delete_queue(&queue), 0);
	if (c_client == -1)
	{
		if (queue == NULL)
			return (0);
		c_client = ((t_client *)queue->content)->client_pid;
	}
	if (ft_queue(c_client, &queue) == MALLOC_FAIL)
		return (ft_lstclear(&queue, &free), exit(-12), 0);
	if (c_client != ((t_client *)queue->content)->client_pid)
		return (0);
	buffer = ft_current_client(queue->content, signal);
	if (buffer == -1 || buffer == FULL_STR)
		ft_delete_queue(&queue);
	if (buffer == MALLOC_FAIL)
		return (ft_lstclear(&queue, &free), exit(-12), 0);
	if (buffer == FULL_STR && queue != NULL)
		ft_use_sigal(1, ((t_client *)queue->content)->client_pid, 0);
	return (0);
}

void	ft_get_signal(int signal, siginfo_t *info, void *ucontext)
{
	ft_use_sigal(signal, info->si_pid, 0);
	(void)ucontext;
}
