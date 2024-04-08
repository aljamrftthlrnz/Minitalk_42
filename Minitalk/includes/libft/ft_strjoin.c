/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 23:36:05 by amirfatt          #+#    #+#             */
/*   Updated: 2022/11/29 17:06:36 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2)
		return (0);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (0);
	i = 0;
	j = 0;
	k = 0;
	while (*s1 && i < ft_strlen(s1))
	{
		s3[k++] = s1[i++];
	}
	while (*s2 && j < ft_strlen(s2))
	{
		s3[k++] = s2[j++];
	}
	s3[k] = '\0';
	return (s3);
}
