/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:05:48 by amirfatt          #+#    #+#             */
/*   Updated: 2023/02/06 14:37:50 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		count = 6;
	}
	else
	{
		while (s[i])
		{
			count += print_char(s[i]);
			i++;
		}
	}
	return (count);
}

static int	count_int(int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		counter;
	int		index;

	counter = count_int(n);
	index = n;
	string = malloc(count_int(n) + 1);
	if (!string)
		return (0);
	while (counter > 0)
	{
		if (n < 0)
			string[counter - 1] = n % 10 * -1 + '0';
		else
			string[counter - 1] = n % 10 + '0';
		n = n / 10;
		counter--;
	}
	if (index < 0)
		string[0] = '-';
	string[count_int(index)] = '\0';
	return (string);
}
