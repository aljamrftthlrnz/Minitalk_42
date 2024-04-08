/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:15:30 by amirfatt          #+#    #+#             */
/*   Updated: 2022/11/29 17:34:13 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_size;
	char	*s_dup;
	size_t	i;

	s_size = ft_strlen(s);
	s_dup = (char *)malloc((sizeof(char)) * s_size + 1);
	if (s_dup == 0)
		return (NULL);
	i = 0;
	while (s[i] && i < s_size)
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}
