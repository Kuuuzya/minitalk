/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:24:47 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/16 09:36:49 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_parser(va_list params, const char *format, int i)
{
	int	count;

	count = 0;
	if (format[i] == 'd' || format[i] == 'i')
		count += ft_printnumber(va_arg(params, int));
	else if (format[i] == 'c')
		count += ft_putchar(va_arg(params, int));
	else if (format[i] == 's')
		count += ft_printstring(va_arg(params, char *));
	else if (format[i] == 'u')
		count += ft_printunsignint(va_arg(params, int));
	else if (format[i] == 'x')
		count += ft_printhex(va_arg(params, unsigned int));
	else if (format[i] == 'X')
		count += ft_printupperhex(va_arg(params, unsigned int));
	else if (format[i] == 'p')
		count += ft_printpointer(va_arg(params, unsigned long));
	else if (format[i] == '%')
		count += ft_printpercent();
	else
		count += ft_putchar(format[i]);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	params;

	i = 0;
	count = 0;
	va_start(params, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_parser(params, format, i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(params);
	return (count);
}

// #include <stdio.h>
// int main()
// {
// 	ft_printf("%c\n%d\n%d\n", 'a', 5, 42);
// 	ft_printf("%s\n", "Hello, World!");
// 	ft_printf("%%\n");
// 	ft_printf("%x\n", 42);
// 	ft_printf("%X\n", 42);
// 	ft_printf("\001\002\007\v\010\f\r\n");
// 	printf("\n\n");
// 	printf("%c\n%d\n%d\n", 'a', 5, 42);
// 	printf("%s\n", "Hello, World!");
// 	printf("%%\n");
// 	printf("%x\n", 42);
// 	printf("%X\n", 42);
// 	printf("\001\002\007\v\010\f\r\n");
// 	return (0);
// }c