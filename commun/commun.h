/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:07:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/03 18:48:48 by tlassere         ###   ########.fr       */
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
char	*ft_copy_at(char *str, size_t size, int c);
int		ft_add_car(char **str, int c, size_t size);
void	*ft_memset(void *s, int c, size_t n);

#endif