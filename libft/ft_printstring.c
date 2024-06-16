/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:53:23 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/16 17:13:13 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putstr(char *s)
{
	if (s == NULL)
		return (0);
	while (*s)
		write(1, s++, 1);
	return (ft_strlen(s));
}

int	ft_printstring(char *s)
{
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
		ft_putstr(s);
	return (ft_strlen(s));
}
