/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:24:24 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/06 17:49:27 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H
# include "../commun/commun.h"

void	ft_get_signal(int signal, siginfo_t *info, void *ucontext);
int		ft_rep_signal(int signal, int delet);
extern int	g_free_instruction;

#endif