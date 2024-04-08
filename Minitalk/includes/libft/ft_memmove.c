/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:09:50 by amirfatt          #+#    #+#             */
/*   Updated: 2022/12/02 18:59:45 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char	*target;
	char	*source;
	size_t	i;

	target = (char *)dest;
	source = (char *)src;
	i = 0;
	if (dest == src)
		return (dest);
	if (target > source)
		while (len-- > 0)
			target[len] = source[len];
	else
	{
		while (i < len)
		{
			target[i] = source[i];
			i++;
		}
	}
	return (dest);
}
