/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:02:12 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/02 21:45:16 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../commun/commun.h"

static int	ft_print_pid(void)
{
	int	pid;

	pid = getpid();
	ft_putstr("Server pid : ");
	if (ft_print_nbr(pid) == -1)
		exit(-12);
	ft_putcar('\n');
	return (pid);
}

static void ft_rep_signal(int signal)
{
	static int	i = 0;
	static char	c = 0;
	
	if (signal == SIGUSR1)
		c = c | 1 << i; 
	i++;
	if (i != 8)
		return ;
	ft_putcar(c);	
	c = 0;
	i = 0;
}

int	main(void)
{
	ft_print_pid();
	signal(SIGUSR1, &ft_rep_signal);
	signal(SIGUSR2, &ft_rep_signal);
	while (1)
		;
	return (0);
}
