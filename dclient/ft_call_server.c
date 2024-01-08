/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:32:56 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/08 23:18:12 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.c"

int ft_call_server(pid_t server)
{
	if (kill(server, SIGUSR1) == -1)
		return (-1);
	pause();
	return (0);
}