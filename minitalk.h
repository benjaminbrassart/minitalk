/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:04:31 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/06 18:57:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define NO_PID 0

# define ERROR_MALLOC "Failed to allocate memor"
# define ERROR_KILL "Failed to send signal"
# define ERROR_ARGC_CLIENT "Expected 2 arguments"
# define ERROR_PID_CLIENT "Expected argument 1 to be a valid process id"
# define ERROR_ARGC_SERVER "Expected no argument"
# define ERROR_SERVER_RESPONSE "Server responded with an error"
# define ERROR_SERVER_TIMEOUT "Server timed-out"

void			*ft_memmove(void *dst, void const *src, unsigned int n);

unsigned int	ft_strlen(char const *s);

void			exit_error(int pid, char const *message);

void			kill_or_die(int pid, int signo);

#endif
