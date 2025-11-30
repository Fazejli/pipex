/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:45:12 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/08 16:49:23 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbr, size_t size)
{
	char	*buffer;

	if (nbr == 0 || size == 0)
	{
		nbr = 1;
		size = 1;
	}
	if (nbr != 0 && nbr * size / size != nbr)
		return (0);
	buffer = malloc(nbr * size);
	if (!buffer)
	{
		free(buffer);
		return (0);
	}
	ft_bzero(buffer, nbr * size);
	return ((void *)buffer);
}
