/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:34:38 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/16 09:37:11 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printpointer(unsigned long n)
{
	char			hex[17];
	int				i;
	int				count;
	unsigned int	digit;

	i = 0;
	count = ft_putchar('0') + ft_putchar('x');
	if (n == 0)
		return (count + ft_putchar('0'));
	while (n > 0)
	{
		digit = n % 16;
		if (digit < 10)
			hex[i] = '0' + digit;
		else
			hex[i] = 'a' + digit - 10;
		i++;
		n /= 16;
	}
	while (i > 0)
		count += ft_putchar(hex[--i]);
	return (count);
}
