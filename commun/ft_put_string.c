/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:29:24 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/09 20:24:06 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

ssize_t	ft_putcar(int c)
{
	return (ft_putchar_fd(c, 1));
}

ssize_t	ft_putstr(char *s)
{
	return (ft_putstr_fd(s, 1));
}

ssize_t	ft_print_nbr(int nbr)
{
	char	*str;
	ssize_t	tmp;

	str = ft_itoa_over(nbr);
	if (str == NULL)
		return (-1);
	tmp = write(1, str, ft_strlen(str));
	free(str);
	return (tmp);
}
