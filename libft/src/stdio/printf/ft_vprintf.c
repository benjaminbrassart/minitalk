/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:54:09 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 03:59:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <stdarg.h>

int	ft_vprintf(char const *fmt, va_list args)
{
	return (ft_vdprintf(1, fmt, args));
}
