/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mterror.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:55:54 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/17 23:54:31 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTERROR_H
# define MTERROR_H

# define ERROR_MALLOC_FAILED "Memory allocation failed. Aborting."
# define ERROR_INVALID_ARGUMENTS "Expected 2 arguments."
# define ERROR_INVALID_PID "Invalid pid."
# define ERROR_KILL_FAILED "Failed to send byte. Aborting."
# define ERROR_KILL_GROUP "Process groups are forbidden."
# define ERROR_KILL_INIT "Init process is forbidden."
# define ERROR_SIGACTION_FAILED "Failed to install signal handler."

int	print_error(char const *error);

#endif
