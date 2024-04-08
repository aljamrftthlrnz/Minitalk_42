/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:32:21 by amirfatt          #+#    #+#             */
/*   Updated: 2022/12/02 19:27:49 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*target;
	char	*source;
	size_t	i;

	target = (char *)dest;
	source = (char *)src;
	if (!(target) && !(source))
		return (0);
	i = 0;
	while (i < n)
	{
		target[i] = source[i];
		i++;
	}
	return (dest);
}
