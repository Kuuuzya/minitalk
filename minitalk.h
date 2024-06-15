/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:53:03 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/15 21:05:43 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_server_state
{
	int				bits_received;
	unsigned char	current_char;
	pid_t			client_pid;
}	t_server_state;

extern t_server_state	g_state;

void	handle_signal(int sig, siginfo_t *info, void *context);
void	send_signal(pid_t pid, int sig);
void	handle_ack(int sig, siginfo_t *info, void *context);
void	send_message(pid_t pid, char *message);

#endif
