/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 12:36:56 by fadzejli          #+#    #+#             */
/*   Updated: 2025/11/08 16:51:03 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **res, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

int	count_words(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

int	len_next(char *str, int start, char c)
{
	int	len;

	len = 0;
	while (str[start] && str[start] == c)
		start++;
	while (str[start] && str[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

char	*put_to_arr(char *str, int len)
{
	char	*res;
	int		i;

	res = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!res || !str)
		return (NULL);
	while (str[i] && i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**ft_split(char *str, char c)
{
	int		words;
	char	**res;
	int		i;
	int		index;
	int		len;

	i = 0;
	index = 0;
	words = count_words(str, c);
	res = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	while (index < words)
	{
		while (str[i] == c)
			i++;
		len = len_next(str, i, c);
		res[index] = put_to_arr(str + i, len);
		if (!res[index])
			return (ft_free(res, index));
		i = i + len;
		index++;
	}
	res[words] = NULL;
	return (res);
}
/*
#include <stdio.h>
int main()
{
	char **res;

	res = ft_split("abcdcef", 'c');
	while (*res)
	{
		printf("%s\n", *res);
		free(*res);
		res++;
	}
	return (0);
}*/