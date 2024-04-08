/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:33:22 by amirfatt          #+#    #+#             */
/*   Updated: 2023/11/26 14:47:10 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_interrupted = 0;

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
		g_interrupted = 1;
}

void	send_str_to_server(char *str, int pid)
{
	int	i;

	i = 0;
	if (pid > 0)
	{
		while (str[i] != '\0')
		{
			if (g_interrupted)
				ft_client_exit(&str, pid);
			if (str[i] == '1')
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_kill_check(&str);
			}
			else if (str[i] == '0')
			{
				if (kill(pid, SIGUSR2) == -1)
					ft_kill_check(&str);
			}
			i++;
			usleep(200);
		}
	}
	else
		ft_printf("Wrong PID!\n");
}

void	char_to_bin(int c, char *res, int pid)
{
	int	j;

	if (g_interrupted)
		ft_client_exit(&res, pid);
	j = 0;
	while (j < 8)
	{
		if (c & (1 << (7 - j)))
			res[j] = '1';
		else
			res[j] = '0';
		j++;
	}
}

char	*create(char *str, int pid)
{
	char	*result;
	int		i;
	int		size;
	int		k;

	size = ft_strlen(str);
	i = 0;
	result = (char *)malloc(((size + 1) * 8) + 1);
	if (!result)
		return (NULL);
	while (i < size)
	{
		if (g_interrupted)
			ft_client_exit(&result, pid);
		char_to_bin((int)str[i], &result[i * 8], pid);
		i++;
	}
	k = 0;
	while (k < 8)
	{
		result[i * 8 + k] = '0';
		k++;
	}
	result[i * 8 + 8] = '\0';
	return (result);
}

int	main(int argc, char **argv)
{
	char				*binary_string;
	int					pid;
	struct sigaction	act;

	if (argc != 3)
	{
		ft_printf("\nUsage: <./client> <PID> <Client message>\n");
		exit(EXIT_FAILURE);
	}
	ft_memset(&act, 0, sizeof(act));
	act.sa_handler = sigint_handler;
	sigaction(SIGINT, &act, NULL);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (ft_printf("Invalid PID."));
	binary_string = create(argv[2], pid);
	if (binary_string == NULL)
		exit(EXIT_FAILURE);
	else
	{
		send_str_to_server(binary_string, pid);
		free(binary_string);
		ft_printf("Client message sent...\n");
	}
	return (0);
}
