/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:52:08 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/16 09:36:58 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnumber(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	if (!num)
		return (0);
	ft_printstring(num);
	len = ft_strlen(num);
	free(num);
	return (len);
}
