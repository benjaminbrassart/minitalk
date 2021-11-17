/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:54:21 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/17 22:51:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_dputnl(int fd, char const *s)
{
	int	printed_chars[2];

	printed_chars[0] = ft_dputs(fd, s);
	if (printed_chars[0] == -1)
		return (-1);
	printed_chars[1] = ft_dputc(fd, '\n');
	if (printed_chars[1] == -1)
		return (-1);
	return (printed_chars[0] + printed_chars[1]);
}
