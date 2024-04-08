/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:02:13 by amirfatt          #+#    #+#             */
/*   Updated: 2024/04/08 10:44:13 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "includes/ft_printf/ft_printf.h"
# include "includes/libft/libft.h"
# include <errno.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <unistd.h>

# define BUFFER 10000

void	reset_message(char **message, int *i);
void	ft_server_exit(char **str);
void	handler(int signal, siginfo_t *info, void *context);
void	binary_to_char(char *s);
void	form_message(unsigned char c, bool value);
void	double_buffer(char **message);

void	ft_client_exit(char **str, int pid);
void	ft_kill_check(char **str);
char	*create(char *str, int pid);
void	char_to_bin(int c, char *res, int pid);
void	send_str_to_server(char *str, int pid);
void	sigint_handler(int signal);

#endif
