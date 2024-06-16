/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:57:33 by skuznets          #+#    #+#             */
/*   Updated: 2024/01/25 02:31:31 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len;

	len = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (dst[len] != '\0' && len < n)
		len++;
	i = 0;
	while ((len + i + 1 < n) && (src[i] != '\0'))
	{
		dst[len + i] = src[i];
		i++;
	}
	if (len != n)
		dst[len + i] = '\0';
	return (ft_strlen(src) + len);
}
