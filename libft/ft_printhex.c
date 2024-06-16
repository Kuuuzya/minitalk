/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:05:18 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/16 09:37:03 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(unsigned int n)
{
	int				count;
	char			hex[17];
	int				i;
	unsigned int	digit;

	i = 0;
	count = 0;
	if (n == 0)
		return (ft_putchar('0'));
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
	while (i--)
	{
		ft_putchar(hex[i]);
		count++;
	}
	return (count);
}
