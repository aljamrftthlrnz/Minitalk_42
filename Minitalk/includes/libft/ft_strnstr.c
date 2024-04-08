/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:10:54 by amirfatt          #+#    #+#             */
/*   Updated: 2022/12/02 15:35:39 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!ft_strlen(little))
		return ((char *)big);
	if (len == 0)
		return (NULL);
	i = 0;
	while (*(big + i) && i < len)
	{
		j = 0;
		while (*(little + j) == *(big + i + j) && (i + j) < len)
		{
			if (!*(little + j + 1))
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
