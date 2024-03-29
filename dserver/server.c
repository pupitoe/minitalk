/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:08 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 20:16:18 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	ft_rep_signal(int signal, t_client *client)
{
	if (client->index == 0)
	{
		client->curent_str = calloc((client->size + 1), sizeof(char));
		if (client->curent_str == NULL)
			return (MALLOC_FAIL);
	}
	if (client->c_bit == 0)
		client->index += 1;
	if (signal == SIGUSR1)
		client->curent_str[client->index - 1] |= 1 << client->c_bit;
	if (++(client->c_bit) == 8)
		client->c_bit = 0;
	if (client->curent_str[client->index - 1] == '\0' && client->c_bit == 0)
	{
		ft_putstr(client->curent_str);
		return (FULL_STR);
	}
	return (FINISH_PACKET);
}

int	ft_get_size(t_client *client, int signal)
{
	if (signal == SIGUSR1)
		client->size |= 1 << client->c_bit;
	client->c_bit += 1;
	if (client->c_bit == sizeof(size_t) * 8)
	{
		client->c_bit = 0;
		return (GET_FULL_SIZE);
	}
	return (FINISH_PACKET);
}

int	ft_current_client(t_client *client, int signal)
{
	int	buffer;

	g_free_instruction = 3;
	buffer = 0;
	if (client->action == NO_ACTION)
	{
		client->action = PUSH_FIRST_PACKET;
		buffer = ft_tcp_client(client->client_pid);
	}
	else if (client->action == PUSH_FIRST_PACKET)
	{
		buffer = ft_get_size(client, signal);
		if (buffer == GET_FULL_SIZE)
			client->action = REP_SIZE;
	}
	else if (client->action == REP_SIZE)
		buffer = ft_rep_signal(signal, client);
	if (buffer == FINISH_PACKET || buffer == GET_FULL_SIZE)
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
