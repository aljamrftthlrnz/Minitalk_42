/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:13:19 by amirfatt          #+#    #+#             */
/*   Updated: 2023/02/06 14:26:26 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int number)
{
	int	count;

	count = 0;
	while (number != 0)
	{
		count++;
		number = number / 16;
	}
	return (count);
}

void	print_hex(unsigned int number, const char specifier)
{
	if (number >= 16)
	{
		print_hex(number / 16, specifier);
		print_hex(number % 16, specifier);
	}
	else
	{
		if (number <= 9)
			print_char(number + '0');
		else
		{
			if (specifier == 'x')
				print_char(number - 10 + 'a');
			if (specifier == 'X')
				print_char(number - 10 + 'A');
		}
	}
}

int	countnbr_xx(unsigned int number, const char specifier)
{
	if (number == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	print_hex(number, specifier);
	return (hex_len(number));
}
