/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:50:25 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/15 21:11:20 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minitalk.h"

// t_server_state g_state = {0, 0, 0};

// void	handle_signal(int sig, siginfo_t *info, void *context)
// {
// 	(void)context;
// 	if (info->si_pid != 0)
// 		g_state.client_pid = info->si_pid;
// 	if (sig == SIGUSR2)
// 		g_state.current_char |= 1 << (7 - g_state.bits_received);
// 	g_state.bits_received++;
// 	if (g_state.bits_received == 8)
// 	{
// 		if (g_state.current_char == 0)
// 			write(1, "\n", 1);
// 		else
// 			write(1, &g_state.current_char, 1);
// 		g_state.bits_received = 0;
// 		g_state.current_char = 0;
// 	}
// 	kill(g_state.client_pid, SIGUSR1);
// }

// int	main(void)
// {
// 	struct sigaction	sa;
// 	pid_t				pid;

// 	pid = getpid();
// 	ft_printf("Server PID: %d\n", pid);
// 	sa.sa_sigaction = handle_signal;
// 	sa.sa_flags = SA_SIGINFO;
// 	if (sigaction(SIGUSR1, &sa, NULL) == -1)
// 	{
// 		ft_printf("Error setting signal handler for SIGUSR1\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (sigaction(SIGUSR2, &sa, NULL) == -1)
// 	{
// 		ft_printf("Error setting signal handler for SIGUSR2\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	while (1)
// 	{
// 		pause();
// 	}
// 	return (0);
// }


#include "minitalk.h"

t_server_state g_state = {0, 0, 0};  // Инициализация глобальной переменной

void handle_signal(int sig, siginfo_t *info, void *context)
{
    (void)context;
    if (info->si_pid != 0)
        g_state.client_pid = info->si_pid;

    if (sig == SIGUSR2)
        g_state.current_char |= 1 << (7 - g_state.bits_received);

    g_state.bits_received++;

    if (g_state.bits_received == 8) {
        if (g_state.current_char == 0) {
            write(1, "\n", 1);
        } else {
            write(1, &g_state.current_char, 1);
        }
        g_state.bits_received = 0;
        g_state.current_char = 0;
    }

    kill(g_state.client_pid, SIGUSR1);  // Отправляем подтверждение клиенту
}

int main(void)
{
    struct sigaction sa;
    pid_t pid = getpid();

    ft_printf("Server PID: %d\n", pid);

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;

    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        ft_printf("Error setting signal handler for SIGUSR1\n");
        exit(EXIT_FAILURE);
    }
    if (sigaction(SIGUSR2, &sa, NULL) == -1) {
        ft_printf("Error setting signal handler for SIGUSR2\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        pause();
    }

    return 0;
}
