/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:12:37 by dozella           #+#    #+#             */
/*   Updated: 2021/11/14 02:22:01 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[i] != 0 && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] != 0 && j + i < len)
			j++;
		if (j == ft_strlen(s2))
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
