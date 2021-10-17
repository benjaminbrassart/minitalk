/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:00:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 04:04:20 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_functions.h"
#include "ft_printf_options.h"
#include "ft_stdio.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			bytes;

	va_start(args, format);
	bytes = ft_vprintf(format, args);
	va_end(args);
	return (bytes);
}
