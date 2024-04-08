/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:17:54 by amirfatt          #+#    #+#             */
/*   Updated: 2022/12/02 19:25:10 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = ft_strlen(s);
	while (i + 1 > -1)
	{
		if (s[i] == (unsigned char)c)
			return (&s[i]);
		i--;
	}
	if ((unsigned char)c == 0)
		return (&s[ft_strlen(s)]);
	return (0);
}
