/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dozella <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 05:38:36 by dozella           #+#    #+#             */
/*   Updated: 2022/01/28 05:38:38 by dozella          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cod(va_list ap, const char cod)
{
	int	print_len;

	print_len = 0;
	if (cod == 'c')
		print_len += ft_pc(va_arg(ap, int));
	else if (cod == 's')
		print_len += ft_ps(va_arg(ap, char *));
	else if (cod == 'p')
		print_len += ft_pp(va_arg(ap, unsigned long long));
	else if (cod == 'd' || cod == 'i')
		print_len += ft_pn(va_arg(ap, int));
	else if (cod == 'u')
		print_len += ft_pu(va_arg(ap, unsigned int));
	else if (cod == 'x' || cod == 'X')
		print_len += ft_ph(va_arg(ap, unsigned int), cod);
	else if (cod == '%')
		print_len += ft_ppr();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_cod(ap, str[i + 1]);
			i++;
		}
		else
			print_len += ft_pc(str[i]);
		i++;
	}
	va_end(ap);
	return (print_len);
}
