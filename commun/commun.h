/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:07:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/02 20:08:29 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMUN_H
# define COMMUN_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

size_t	ft_strlen(char *s);
ssize_t	ft_putstr(char *s);
ssize_t	ft_putcar(int c);
ssize_t	ft_print_nbr(int nbr);
char	*ft_itoa(int nbr);

#endif