/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:25:51 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 08:42:47 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

void		check_args(int argc, char *argv[]);

void		on_error(int sig);

void		on_success(int sig);

int			send_byte(int pid, unsigned char byte);

int			send_wait(int pid, int bit);

#endif