/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 00:22:36 by tlassere          #+#    #+#             */
/*   Updated: 2024/01/08 21:45:45 by tlassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.h"

static int	ft_get_size(int nbr)
{
	int	len;

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

char	*ft_itoa_over(int nbr)
{
	char	*str;
	int		len;

	len = ft_get_size(nbr);
	str = malloc(len * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len - 1] = '\0';
	while (len > 1)
	{
		str[len - 2] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (str);
}
