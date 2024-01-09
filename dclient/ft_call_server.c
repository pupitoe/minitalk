/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:32:56 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 15:05:27 by tlassere         ###   ########.fr       */
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
