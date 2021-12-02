/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:32:37 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/02 00:57:23 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERROR_MALLOC "Failed to allocate memory"
# define ERROR_KILL "Failed to send signal"
# define ERROR_ARGC_CLIENT "Expected 2 arguments"
# define ERROR_ARGC_SERVER "Expected no argument"
# define ERROR_ARGV_PID "Expected argument 1 to be a valid process id"
# define ERROR_SERVER_RESPONSE "Server response indicates an error"
# define ERROR_SERVER_TIMEOUT "Server took too long to respond"

# define NO_PID -1

unsigned int	ft_strlen(char const *s);

void			*ft_memmove(void *dst, void const *src, unsigned int n);

void			exit_error(int pid, char const *message);

void			try_kill(int pid, int signo);

#endif
