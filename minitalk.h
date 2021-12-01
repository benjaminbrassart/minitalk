/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:32:37 by bbrassar          #+#    #+#             */
/*   Updated: 2021/12/01 23:45:58 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define ERROR_MALLOC "Failed to allocate memory"
# define ERROR_KILL "Failed to send signal"
# define ERROR_ARGC "Expected 2 arguments"
# define ERROR_ARGV_PID "Expected argument 1 to be a valid process id"

void	exit_error(char const *message);

void	try_kill(int pid, int signo);

#endif
