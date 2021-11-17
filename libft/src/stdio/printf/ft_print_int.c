/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 07:54:48 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 20:26:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf_options.h"
#include "ft_printf_functions.h"

static int	ft_intsize(int i, t_opt *opt)
{
	int				sz;
	unsigned int	n;

	if (!(!(opt->flags & PRECISION) || opt->precision || i))
		return (0);
	sz = 1;
	if (i < 0)
		n = -i;
	else
		n = i;
	while (n / 10)
	{
		++sz;
		n /= 10;
	}
	return (sz);
}

static void	ft_putint(int i, int b)
{
	unsigned int	n;

	if (i < 0)
		n = -i;
	else
		n = i;
	if (--b > 0)
		ft_putint(n / 10, b);
	ft_putc(BASE_HEX[n % 10]);
}

int	putsign(t_opt *opt, int n)
{
	int	bytes;

	bytes = 0;
	if (n < 0)
		bytes += write(opt->fd, "-", 1);
	else
	{
		if (opt->flags & PLUS)
			bytes += write(opt->fd, "+", 1);
		else if (opt->flags & SPACE)
			bytes += write(opt->fd, " ", 1);
	}
	return (bytes);
}

int	ft_print_int(t_opt *opt, va_list args)
{
	int	n;
	int	bytes;
	int	digits;

	n = va_arg(args, int);
	digits = ft_intsize(n, opt);
	if ((opt->flags & PRECISION) && digits < opt->precision)
		digits = opt->precision;
	if (opt->flags & PRECISION)
		opt->flags &= ~ZERO;
	bytes = digits;
	while ((opt->flags & MIN_WIDTH) && !(opt->flags & ZERO)
		&& opt->min_width > (bytes + !!(n < 0 || opt->flags & (PLUS | SPACE))))
		bytes += write(opt->fd, " ", 1);
	bytes += putsign(opt, n);
	while ((opt->flags & ZERO) && opt->min_width > bytes)
		bytes += write(opt->fd, "0", 1);
	if (!(opt->flags & PRECISION && opt->precision == 0 && n == 0))
		ft_putint(n, digits);
	while ((opt->flags & DASH) && opt->min_width > bytes)
		bytes += write(opt->fd, " ", 1);
	return (bytes);
}
