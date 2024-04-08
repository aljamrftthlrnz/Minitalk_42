/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:32:55 by amirfatt          #+#    #+#             */
/*   Updated: 2023/11/26 14:43:30 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_pid = 0;

void	double_buffer(char **message)
{
	char	*temp;

	temp = ft_calloc(ft_strlen(*message) + BUFFER, sizeof(char));
	if (!temp)
	{
		free(*message);
		exit(1);
	}
	ft_strlcpy(temp, *message, ft_strlen(*message) + 1);
	free(*message);
	*message = temp;
}

void	form_message(unsigned char c, bool value)
{
	static char	*message;
	static int	i;

	if (value)
		ft_server_exit(&message);
	if (!message)
	{
		message = ft_calloc(BUFFER, 1);
		if (!message)
			exit(1);
	}
	if (ft_strlen(message) > 0 && ft_strlen(message) % BUFFER == 0)
		double_buffer(&message);
	if (c != '\0')
		message[i++] = c;
	else
	{
		message[i] = '\0';
		ft_printf("%s\n", message);
		reset_message(&message, &i);
	}
}

void	binary_to_char(char *s)
{
	unsigned char	result;
	int				length;
	int				i;

	result = 0;
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		if (s[i] == '1')
			result = result * 2 + 1;
		else if (s[i] == '0')
			result = result * 2;
		i++;
	}
	form_message(result, false);
}

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static char	acc_bits[8];

	if (!g_pid)
		g_pid = info->si_pid;
	if (g_pid != info->si_pid)
	{
		g_pid = info->si_pid;
		i = 0;
		ft_memset(acc_bits, 0, 8);
	}
	(void)context;
	if (signal == SIGINT)
		form_message(' ', true);
	if (signal == SIGUSR1)
		acc_bits[i] = '1';
	else if (signal == SIGUSR2)
		acc_bits[i] = '0';
	i++;
	if (i == 8)
	{
		binary_to_char(acc_bits);
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Ready to receive messages from client...\n");
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	while (1)
		pause();
	return (0);
}
