/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:08 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/08 23:17:31 by tlassere         ###   ########.fr       */
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


t_list *ft_creat_el(pid_t client)
{
	t_list		*new_lst;
	t_client	*lst_content;

	lst_content = malloc(sizeof(t_client));
	if (lst_content == NULL)
		return (NULL);
	new_lst = ft_lstnew(lst_content);
	if (new_lst == NULL)
		return (free(lst_content), NULL);
	lst_content->client_pid = client;
	return (new_lst);
}

int	ft_check_content(t_list *lst, pid_t client)
{
	if (lst == NULL)
		return (0);
	if ((t_client)lst->content == client)
		return (1);
	return (ft_check_content(lst->next, client));
}

int		ft_queue(pid_t client, t_list *queue)
{
	t_list	*new_client;


	return (0);
}

void	ft_get_signal(int signal, siginfo_t *info, void *ucontext)
{
	static pid_t	client_pid = -1;

	if (client_pid == -1)
		client_pid = info->si_pid;
	else if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		ft_rep_signal(0, 1);
	}
	if (ft_rep_signal(signal, 0) == -1)
		exit(1);
	usleep(100);
	if (kill(client_pid, SIGUSR1) == -1)
	{
		ft_rep_signal(0, 1);
		exit(1);
	}
	g_free_instruction = 3;
	(void)ucontext;
}
