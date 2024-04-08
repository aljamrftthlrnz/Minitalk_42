/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:04:45 by amirfatt          #+#    #+#             */
/*   Updated: 2023/02/06 15:59:13 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_controller(va_list arg, char specifier)
{
	int	count;

	count = 0;
	if (specifier == '%')
		count += print_char('%');
	else if (specifier == 'c')
		count += print_char(va_arg(arg, int));
	else if (specifier == 's')
		count += print_str(va_arg(arg, char *));
	else if (specifier == 'u')
		count += printnbr_u(va_arg(arg, unsigned int));
	else if (specifier == 'i' || specifier == 'd')
		count += printnbr_id(va_arg(arg, int));
	else if (specifier == 'p')
		count += countnbr_ptr(va_arg(arg, unsigned long long));
	else if (specifier == 'x' || specifier == 'X')
		count += countnbr_xx(va_arg(arg, int), specifier);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arguments;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(arguments, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_controller(arguments, s[i + 1]);
			i++;
		}
		else
			count += print_char(s[i]);
		i++;
	}
	va_end(arguments);
	return (count);
}
