/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:53:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 07:03:20 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_functions.h"
#include "ft_printf_options.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static int	exec_format(int fd, char const **format, va_list args)
{
	int			bytes;
	t_opt		opt;
	t_printer	printer;

	opt = ft_parse_options(format, args);
	opt.fd = fd;
	printer = ft_get_printer(**format);
	if (printer.fn)
		bytes = printer.fn(&opt, args);
	else
		bytes = ft_print_raw(&opt, **format);
	return (bytes);
}

int	ft_vdprintf(int fd, char const *fmt, va_list args)
{
	int	bytes;

	bytes = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			bytes += exec_format(fd, &fmt, args);
		}
		else
			bytes += write(fd, fmt, 1);
		++fmt;
	}
	return (bytes);
}
