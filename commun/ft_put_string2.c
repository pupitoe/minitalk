/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:47:29 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/07 17:19:28 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

char	*ft_add_car_str(char *str, size_t size, int c)
{
	char	*buffer;
	size_t	i;

	buffer = malloc(size * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[size - 1] = c;
	return (buffer);
}

int	ft_add_car(char **str, int c, size_t size)
{
	char	*buffer;

	buffer = *str;
	*str = ft_add_car_str(buffer, size, c);
	if (buffer != NULL)
		free(buffer);
	if (*str == NULL)
		return (-1);
	return (0);
}
