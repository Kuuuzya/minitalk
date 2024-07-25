/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:36:28 by skuznets          #+#    #+#             */
/*   Updated: 2024/07/25 17:05:40 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_atoi(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, \
		size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_isdigit(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
#endif