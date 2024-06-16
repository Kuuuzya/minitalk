/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:53:03 by skuznets          #+#    #+#             */
/*   Updated: 2024/06/16 10:35:45 by skuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

void	handle_signal(int sig, siginfo_t *info, void *context);
void	send_char(pid_t server_pid, unsigned char c);
void	ack_handler(int sig);
void	send_string(pid_t server_pid, const char *str);
#endif
