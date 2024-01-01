/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:22:36 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/02 00:34:17 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

int	ft_get_size(int nbr)
{
	int len;

	len = 1;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	if (len == 1)
		len++;
	return (len);	
}

char	*itoa(int nbr)
{
	char	*str;
	int		len;

	len = ft_get_size(nbr);
	nbr = malloc(len);
	if (nbr == NULL)
		return (NULL);
	str[len - 1] = '\0';
	while (len > 1)
	{
		str[len - 2] = nbr % 10;
		nbr /= 10;
		len--;
	}
	return (str);
}