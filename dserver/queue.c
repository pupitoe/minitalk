/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 00:27:39 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 17:51:01 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_list	*ft_creat_el(pid_t client)
{
	t_list		*new_lst;
	t_client	*lst_content;

	lst_content = malloc(sizeof(t_client));
	if (lst_content == NULL)
		return (NULL);
	new_lst = ft_lstnew(lst_content);
	if (new_lst == NULL)
		return (free(lst_content), NULL);
	ft_bzero(lst_content, sizeof(t_client));
	lst_content->client_pid = client;
	return (new_lst);
}

int	ft_check_content(t_list *lst, pid_t client)
{
	if (lst == NULL)
		return (0);
	if (((t_client *)lst->content)->client_pid == client)
		return (1);
	return (ft_check_content(lst->next, client));
}

void	ft_free_queue(void *cur_client)
{
	t_client	*client;

	client = cur_client;
	if (client->curent_str)
		free(client->curent_str);
	free(cur_client);
}

void	ft_delete_queue(t_list **queue)
{
	t_list	*buffer;

	if (queue == NULL || *queue == NULL)
		return ;
	buffer = (*queue)->next;
	ft_lstdelone(*queue, &ft_free_queue);
	*queue = buffer;
}

int	ft_queue(pid_t client, t_list **queue)
{
	t_list	*new_client;

	if (ft_check_content(*queue, client))
		return (0);
	new_client = ft_creat_el(client);
	if (new_client == NULL)
		return (MALLOC_FAIL);
	ft_lstadd_back(queue, new_client);
	return (0);
}
