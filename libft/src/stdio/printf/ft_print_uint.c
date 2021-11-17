/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 07:24:42 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 20:26:44 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf_options.h"
#include "ft_printf_functions.h"

static int	ft_uint_size(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		++i;
		n /= 10;
	}
	return (i);
}

static void	ft_putuint(unsigned int n, int b)
{
	if (--b > 0)
		ft_putuint(n / 10, b);
	ft_putc(BASE_HEX[n % 10]);
}

int	ft_print_uint(t_opt *opt, va_list args)
{
	int				bytes;
	int				digits;
	unsigned int	n;

	n = va_arg(args, unsigned int);
	digits = ft_uint_size(n);
	if (digits < opt->precision)
		digits = opt->precision;
	if (opt->flags & PRECISION)
		opt->flags &= ~ZERO;
	bytes = digits;
	if (opt->flags & PRECISION && opt->precision == 0 && n == 0)
		bytes = 0;
	while ((opt->flags & ZERO) && opt->min_width > bytes)
		bytes += write(opt->fd, "0", 1);
	while ((opt->flags & MIN_WIDTH) && opt->min_width > bytes)
		bytes += write(opt->fd, " ", 1);
	if (!(opt->flags & PRECISION && opt->precision == 0 && n == 0))
		ft_putuint(n, digits);
	while ((opt->flags & DASH) && opt->min_width > bytes)
		bytes += write(opt->fd, " ", 1);
	return (bytes);
}
