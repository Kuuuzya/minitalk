/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   client.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: skuznets <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/06/15 19:37:48 by skuznets		  #+#	#+#			 */
/*   Updated: 2024/06/15 20:00:41 by skuznets		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

void	send_signal(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Error sending signal\n");
		exit(EXIT_FAILURE);
	}
}

void	send_message(pid_t pid, char *message)
{
	int	i;

	while (*message)
	{
		i = 0;
		while (i < 8)
		{
			if (*message & (1 << (7 - i)))
				send_signal(pid, SIGUSR2);
			else
				send_signal(pid, SIGUSR1);
			usleep(10);
			i++;
		}
		message++;
	}
	i = 0;
	while (i < 8)
	{
		send_signal(pid, SIGUSR1);
		usleep(10);
		i++;
	}
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Usage: %s <PID> <message>\n", av[0]);
		return (1);
	}
	pid = ft_atoi(av[1]);
	send_message(pid, av[2]);
	return (0);
}
