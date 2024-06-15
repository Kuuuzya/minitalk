/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:01:04 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/15 21:11:06 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"

// void send_signal(pid_t pid, int sig)
// {
// 	if (kill(pid, sig) == -1) {
// 		ft_printf("Error sending signal\n");
// 		exit(EXIT_FAILURE);
// 	}
// }

// void handle_ack(int sig, siginfo_t *info, void *context)
// {
// 	(void)sig;
// 	(void)info;
// 	(void)context;
// 	int *acknowledged = (int *)context;
// 	*acknowledged = 1;
// }

// void send_message(pid_t pid, char *message)
// {
// 	struct sigaction sa_ack;
// 	int i;
// 	int acknowledged = 0;

// 	sa_ack.sa_sigaction = handle_ack;
// 	sa_ack.sa_flags = 0;
// 	sigemptyset(&sa_ack.sa_mask);

// 	if (sigaction(SIGUSR1, &sa_ack, NULL) == -1)
// 	{
// 		ft_printf("Error setting signal handler for acknowledgment\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	while (*message)
// 	{
// 		i = 0;
// 		while (i < 8)
// 		{
// 			acknowledged = 0;
// 			if (*message & (1 << (7 - i))) 
// 				send_signal(pid, SIGUSR2);
// 			else
// 				send_signal(pid, SIGUSR1);
// 			while (!acknowledged)
// 				pause();  // Ожидаем подтверждение от сервера
// 		i++;
// 		}
// 		message++;
// 	}
// 	i = 0;
// 	while (i < 8) {
// 		acknowledged = 0;
// 		send_signal(pid, SIGUSR1);
// 		while (!acknowledged)
// 			pause();  // Ожидаем подтверждение от сервера
// 		i++;
// 	}
// }

// int main(int ac, char *av[])
// {
// 	if (ac != 3) {
// 		ft_printf("Usage: %s <PID> <message>\n", av[0]);
// 		return (1);
// 	}
// 	pid_t pid = ft_atoi(av[1]);
// 	send_message(pid, av[2]);
// 	return (0);
// }


#include "minitalk.h"

void send_signal(pid_t pid, int sig)
{
    if (kill(pid, sig) == -1) {
        ft_printf("Error sending signal\n");
        exit(EXIT_FAILURE);
    }
}

void handle_ack(int sig, siginfo_t *info, void *context)
{
    (void)sig;
    (void)info;
    int *acknowledged = (int *)context;
    *acknowledged = 1;
}

void send_message(pid_t pid, char *message)
{
    struct sigaction sa_ack;
    int acknowledged = 0;  // Локальная переменная для хранения состояния подтверждения

    sa_ack.sa_sigaction = handle_ack;
    sa_ack.sa_flags = SA_SIGINFO | SA_RESTART;
    sigemptyset(&sa_ack.sa_mask);

    if (sigaction(SIGUSR1, &sa_ack, (void *)&acknowledged) == -1) {
        ft_printf("Error setting signal handler for acknowledgment\n");
        exit(EXIT_FAILURE);
    }

    while (*message) {
        int i = 0;
        while (i < 8) {
            acknowledged = 0;
            if (*message & (1 << (7 - i))) {
                send_signal(pid, SIGUSR2);
            } else {
                send_signal(pid, SIGUSR1);
            }
            while (!acknowledged)
                pause();  // Ожидаем подтверждение от сервера
            i++;
        }
        message++;
    }
    int i = 0;
    while (i < 8) {
        acknowledged = 0;
        send_signal(pid, SIGUSR1);
        while (!acknowledged)
            pause();  // Ожидаем подтверждение от сервера
        i++;
    }
}

int main(int ac, char *av[])
{
    if (ac != 3) {
        ft_printf("Usage: %s <PID> <message>\n", av[0]);
        return 1;
    }
    pid_t pid = ft_atoi(av[1]);
    send_message(pid, av[2]);
    return 0;
}
