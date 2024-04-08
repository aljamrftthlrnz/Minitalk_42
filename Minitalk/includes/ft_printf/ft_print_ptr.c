/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:22:30 by amirfatt          #+#    #+#             */
/*   Updated: 2023/02/06 15:58:19 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ptr_len(unsigned long number)
{
	int	length;

	length = 0;
	while (number)
	{
		length++;
		number = number / 16;
	}
	return (length);
}

void	print_ptr(unsigned long number)
{
	if (number >= 16)
	{
		print_ptr(number / 16);
		print_ptr(number % 16);
	}
	else
	{
		if (number <= 9)
			ft_putchar_fd((number + '0'), 1);
		else
			ft_putchar_fd((number - 10 + 'a'), 1);
	}
}

int	countnbr_ptr(unsigned long number)
{
	int	count;

	count = 0;
	if (number == 0)
	{
		count += write(1, "(nil)", 5);
	}
	else
	{
		count += write(1, "0x", 2);
		print_ptr(number);
		count += ptr_len(number);
	}
	return (count);
}
