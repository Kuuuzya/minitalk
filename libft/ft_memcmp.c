/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:01:19 by skuznets          #+#    #+#             */
/*   Updated: 2024/01/22 18:01:39 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char *)arr1;
	str2 = (char *)arr2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)((unsigned char)str1[i] - (unsigned char)str2[i]));
		i++;
	}
	return (0);
}
