/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:42:05 by amirfatt          #+#    #+#             */
/*   Updated: 2023/11/26 14:54:05 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_client_exit(char **str, int pid)
{
	int	i;

	i = 15;
	ft_printf("\nClient: SIGINT received, exiting...\n");
	while (i >= 0)
	{
		kill(pid, SIGUSR2);
		i--;
	}
	free(*str);
	exit(EXIT_SUCCESS);
}

void	ft_kill_check(char **str)
{
	free(*str);
	exit(EXIT_FAILURE);
}
