/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amirfatt <amirfatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:39:55 by amirfatt          #+#    #+#             */
/*   Updated: 2023/02/06 15:53:44 by amirfatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
int		print_char(int c);
int		print_str(char *s);
int		hex_len(unsigned int number);
int		printnbr_u(unsigned int number);
int		printnbr_id(int number);
char	*convert_nbr(unsigned int number);
int		countnbr_xx(unsigned int number, const char specifier);
int		nbr_len(unsigned int number);
int		countnbr_ptr(unsigned long number);
int		ptr_len(unsigned long number);
int		ft_controller(va_list arg, char specifier);
char	*ft_itoa(int n);
void	print_hex(unsigned int number, const char specifier);
void	print_ptr(unsigned long number);

#endif