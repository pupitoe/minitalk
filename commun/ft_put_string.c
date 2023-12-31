/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:29:24 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/03 13:47:05 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_putcar(int c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(char *s)
{
	if (s == NULL)
		return (-1);
	return (write(1, s, ft_strlen(s)));
}

ssize_t	ft_print_nbr(int nbr)
{
	char	*str;
	ssize_t	tmp;

	str = ft_itoa(nbr);
	if (str == NULL)
		return (-1);
	tmp = write(1, str, ft_strlen(str));
	free(str);
	return (tmp);
}
