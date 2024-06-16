#include "minitalk.h"
#include <stdio.h>

void handle_signal(int sig, siginfo_t *info, void *context)
{
    static int client_pid = 0;
    static char c = 0;
    static int bits = 0;

    (void)context; // Не используется

    // Обновляем PID клиента, если он не равен нулю
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
        {
            write(1, "\n", 1); // Конец строки
        }
        else
        {
            write(1, &c, 1);
        }
        bits = 0;
        c = 0;
    }

    // Отправляем сигнал подтверждения клиенту
    if (client_pid != 0)
    {
        if (kill(client_pid, SIGUSR1) == -1)
        {
            perror("Failed to send acknowledgment");
            exit(1);
        }
    }
}

int main(void)
{
    struct sigaction sa;

    // Выводим PID сервера
    ft_printf("Server PID: %d\n", getpid());
    
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause();
    return 0;
}
