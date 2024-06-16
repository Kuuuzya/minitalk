/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:26:24 by skuznets          #+#    #+#             */
/*   Updated: 2024/03/20 19:36:57 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_printstring(char *s);
int	ft_printnumber(int n);
int	ft_printpercent(void);
int	ft_printunsignint(unsigned int n);
int	ft_printhex(unsigned int n);
int	ft_printupperhex(unsigned int n);
int	ft_printpointer(unsigned long n);
#endif