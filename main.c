/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:56:14 by tlassere          #+#    #+#             */
/*   Updated: 2023/12/21 15:48:32 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/ft_pipex.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(void)
{
	int	id = fork();
	if (wait(NULL) != -1)
		printf("hi i'm a shildren\n");
	printf("uwu\n%d\n", id);
	if (id == 0)
	{
		printf("hey i'm a little child, i love kill my self bitch\n");
		printf("Are you an filosoph\nkiss kiss but where are your fork\n");
	}
	(void)id;
	return (0);
}
