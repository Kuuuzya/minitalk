/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:13:31 by skuznets          #+#    #+#             */
/*   Updated: 2024/07/25 17:07:19 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

static int	g_ack;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	send_string(char *message, size_t len, const int pid)
{
	int		bit;
	int		signal;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 8)
		{
			bit = message[i] >> j & 1;
			g_ack = 0;
			if (bit)
				signal = SIGUSR1;
			else
				signal = SIGUSR2;
			if (kill(pid, signal) != 0)
				exit(1);
			while (!g_ack)
				;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char				*message;
	pid_t				server_pid;
	struct sigaction	sigact;

	while (sigemptyset(&sigact.sa_mask) != 0)
		;
	while (sigaction(SIGUSR1, &sigact, NULL))
		;
	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client <server_pid> <message>\n", 1);
		exit(1);
	}
	else
	{
		server_pid = ft_atoi(argv[1]);
		message = malloc(ft_strlen(argv[2]) + 1);
		if (!message)
			exit(1);
		ft_strlcpy(message, argv[2], ft_strlen(argv[2]) + 1);
		signal(SIGUSR1, ack_handler);
		send_string(message, ft_strlen(message) + 1, server_pid);
		free(message);
	}
	return (0);
}
