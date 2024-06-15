/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:21:04 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/15 20:32:03 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

//sigaction

static void	handle_signal(int sig)
{
	static int				bits_received;
	static unsigned char	current_char;

	bits_received = 0;
	current_char = 0;
	if (sig == SIGUSR2)
		current_char |= 1 << (7 - bits_received);
	bits_received++;
	if (bits_received == 8)
	{
		if (current_char == 0)
			write(1, "\n", 1);
		else
			write(1, &current_char, 1);
		bits_received = 0;
		current_char = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	if (signal(SIGUSR1, handle_signal) == SIG_ERR)
	{
		ft_printf("Error setting signal handler for SIGUSR1\n");
		exit(EXIT_FAILURE);
	}
	if (signal(SIGUSR2, handle_signal) == SIG_ERR)
	{
		ft_printf("Error setting signal handler for SIGUSR2\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
