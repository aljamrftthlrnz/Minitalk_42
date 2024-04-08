/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:43:37 by amirfatt          #+#    #+#             */
/*   Updated: 2023/11/26 14:44:26 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	reset_message(char **message, int *i)
{
	if (*message)
	{
		ft_memset(*message, 0, *i);
		ft_printf("End of message______%s\n", *message);
	}
	*i = 0;
}

void	ft_server_exit(char **str)
{
	ft_printf("\nServer: SIGINT received, exiting...");
	free(*str);
	exit(EXIT_SUCCESS);
}
