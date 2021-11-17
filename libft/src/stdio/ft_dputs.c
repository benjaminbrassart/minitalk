/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:14:02 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 18:50:08 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include "ft_string.h"
#include <unistd.h>

int	ft_dputs(int fd, char const *s)
{
	return (write(fd, s, ft_strlen(s)));
}
