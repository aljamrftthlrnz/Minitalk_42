/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:25:00 by amirfatt          #+#    #+#             */
/*   Updated: 2022/11/29 17:04:48 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*usc;
	size_t			i;

	i = 0;
	usc = (unsigned char *)s;
	while (i < n)
	{
		*usc = (unsigned char)c;
		i++;
		usc++;
	}
	return (s);
}
