/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:02:47 by skuznets          #+#    #+#             */
/*   Updated: 2024/07/25 16:58:13 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	client_pid;
	static char	c;
	static int	bits;

	(void)context;
	if (info->si_pid != 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << bits);
	else if (sig == SIGUSR2)
		c &= ~(1 << bits);
	bits++;
	if (bits == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bits = 0;
		c = 0;
	}
	if (client_pid != 0)
		if (kill(client_pid, SIGUSR1) == -1)
			exit(1);
}

int	main(void)
{
	struct sigaction	sigact;

	ft_printf("Server PID: %d\n", getpid());
	sigact.sa_sigaction = handle_signal;
	sigemptyset(&sigact.sa_mask);
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	system("leaks server");
	return (0);
}
