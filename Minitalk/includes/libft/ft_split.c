/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:44:43 by amirfatt          #+#    #+#             */
/*   Updated: 2022/11/29 17:31:41 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	size_t	reset;
	size_t	count;

	count = 0;
	reset = 0;
	while (*s)
	{
		if (*s != c && reset == 0)
		{
			reset = 1;
			count++;
		}
		else if (*s == c)
			reset = 0;
		s++;
	}
	return (count);
}

static int	ft_cstrlen(char *word, char c)
{
	int	i;

	i = 0;
	while (word[i] != c && word[i])
		i++;
	return (i);
}

static char	**justdoit(char *str, char c, char **finito)
{
	int	array;
	int	i;
	int	wordsize;

	array = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			wordsize = ft_cstrlen(&str[i], c);
			finito[array] = ft_substr(&str[i], 0, wordsize);
			array++;
		}
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	finito[array] = (char *)0;
	return (finito);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**finito;
	int		wcount;

	str = (char *)s;
	wcount = word_count(s, c);
	if (s[0] == '\0')
	{
		finito = malloc(sizeof(char *));
		finito[0] = 0;
		return (finito);
	}
	finito = malloc((wcount + 1) * sizeof(char *));
	if (!finito)
		return (finito);
	return (justdoit(str, c, finito));
}
