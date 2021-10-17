/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:49:20 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 03:58:09 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_functions.h"
#include "ft_printf_options.h"
#include "ft_stdio.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_dprintf(int fd, char const *format, ...)
{
	va_list		args;
	int			bytes;

	va_start(args, format);
	bytes = ft_vdprintf(fd, format, args);
	va_end(args);
	return (bytes);
}
