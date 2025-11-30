/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:37:00 by fadzejli          #+#    #+#             */
/*   Updated: 2025/07/16 12:49:26 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	j;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = (char *)ft_calloc(1, sizeof(char) *(s1len + s2len + 2));
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	res[i] = '/';
	i++;
	j = -1;
	while (s2[++j])
	{
		res[i] = s2[j];
		i++;
	}
	return (res);
}
