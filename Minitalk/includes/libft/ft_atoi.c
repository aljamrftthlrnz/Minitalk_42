/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:15:08 by amirfatt          #+#    #+#             */
/*   Updated: 2022/11/29 17:03:20 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	result;
	size_t	sign;
	size_t	i;
	char	*ptr;

	ptr = (char *)str;
	result = 0;
	sign = 1;
	i = 0;
	while ((ptr[i] > 8 && ptr[i] < 14) || ptr[i] == ' ')
		i++;
	if (ptr[i] == '-' || ptr[i] == '+')
	{
		if (ptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(ptr[i]))
	{
		result = result * 10 + ptr[i] - '0';
		i++;
	}
	return (sign * result);
}
