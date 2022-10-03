/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 05:35:09 by dozella           #+#    #+#             */
/*   Updated: 2022/01/28 05:37:05 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int num, const char cod)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, cod);
		ft_puthex(num % 16, cod);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (cod == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (cod == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_ph(unsigned int num, const char cod)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, cod);
	return (ft_hexlen(num));
}
