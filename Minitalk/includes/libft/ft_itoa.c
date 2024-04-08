/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:33:21 by amirfatt          #+#    #+#             */
/*   Updated: 2022/12/02 19:14:10 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
