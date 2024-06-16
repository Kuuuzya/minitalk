/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:04:53 by skuznets          #+#    #+#             */
/*   Updated: 2024/01/25 12:20:46 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nlen(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_add_to_str(char *str, long int num, size_t len)
{
	while (len--)
	{
		*(str + len) = num % 10 + '0';
		num = num / 10;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	long int	num;

	num = n;
	len = nlen(n);
	if (n <= 0)
	{
		num *= -1;
		len++;
	}
	if (n == 0)
		str = (char *)malloc(2);
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_add_to_str(str, num, len);
	if (n < 0)
		*(str + 0) = '-';
	*(str + len) = 0;
	return (str);
}
