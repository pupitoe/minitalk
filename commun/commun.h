/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commun.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:07:21 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 00:10:49 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMUN_H
# define COMMUN_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>
# include "../libft/libft.h"

ssize_t	ft_putstr(char *s);
ssize_t	ft_putcar(int c);
ssize_t	ft_print_nbr(int nbr);
char	*ft_itoa_over(int nbr);
char	*ft_add_car_str(char *str, size_t size, int c);
int		ft_add_car(char **str, int c, size_t size);

#endif