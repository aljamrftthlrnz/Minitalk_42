/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:36:10 by amirfatt          #+#    #+#             */
/*   Updated: 2023/02/06 14:27:24 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_len(unsigned int number)
{
	int	length;

	length = 0;
	while (number != 0)
	{
		length++;
		number = number / 10;
	}
	return (length);
}

char	*convert_nbr(unsigned int number)
{
	int		length;
	char	*numb;

	length = nbr_len(number);
	numb = malloc(sizeof(char) * (length + 1));
	if (!numb)
		return (0);
	numb[length] = '\0';
	while (number)
	{
		numb[length - 1] = number % 10 + '0';
		number = number / 10;
		length--;
	}
	return (numb);
}

int	printnbr_id(int number)
{
	int		count;
	char	*numb;

	count = 0;
	if (number == 0)
		return (write(1, "0", 1));
	numb = ft_itoa(number);
	count = print_str(numb);
	free(numb);
	return (count);
}

int	printnbr_u(unsigned int number)
{
	int		count;
	char	*numb;

	count = 0;
	if (number == 0)
		count += write(1, "0", 1);
	else
	{
		numb = convert_nbr(number);
		count = print_str(numb);
		free(numb);
	}
	return (count);
}
