/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:25:51 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/19 06:05:11 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include "colors.h"
# include "ft_def.h"
# include "minitalk.h"

typedef struct s_client	t_client;

struct s_client
{
	int			server_pid;
	char const	*message;
	char const	*current_char;
};

t_bool		check_args(int argc, char *argv[]);

int			send_byte(int pid, unsigned char byte);

t_bool		send_wait(int pid, int bit);

t_client	*get_client(void);

int			get_sig(char byte, int bit);

#endif
