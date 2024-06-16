#include "minitalk.h"
#include <stdio.h>

volatile sig_atomic_t g_ack = 0;

void ack_handler(int sig)
{
    (void)sig;
    g_ack = 1;
}

void send_byte(pid_t server_pid, unsigned char byte)
{
    for (int i = 0; i < 8; i++)
    {
        g_ack = 0;
        if (byte & (1 << i))
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);

        // Ждем подтверждения от сервера
        int attempts = 0;
        while (!g_ack)
        {
            usleep(100); // Небольшая задержка
            attempts++;
            if (attempts > 10000) // Ограничение на количество попыток
            {
                fprintf(stderr, "Error: Server not responding\n");
                exit(1);
            }
        }
    }
}

void send_string(pid_t server_pid, const char *str)
{
    size_t len = ft_strlen(str);
    for (size_t i = 0; i < len; i++)
    {
        send_byte(server_pid, (unsigned char)str[i]);
        printf("Sent byte: %02x\n", (unsigned char)str[i]);
    }
    // Отправляем символ конца строки
    send_byte(server_pid, '\0');
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "Usage: ./client <server_pid> <message>\n", 39);
        exit(1);
    }

    pid_t server_pid = atoi(argv[1]);
    char *message = argv[2];

    // Устанавливаем обработчик подтверждений от сервера
    signal(SIGUSR1, ack_handler);

    send_string(server_pid, message);

    return 0;
}