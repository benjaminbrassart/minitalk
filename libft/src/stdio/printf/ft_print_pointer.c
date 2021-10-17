/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 07:32:58 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 03:51:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf_options.h"
#include "ft_printf_functions.h"

static int	ft_hex_size(unsigned long int n)
{
	int	i;

	i = 1;
	while (n / 16)
	{
		++i;
		n /= 16;
	}
	return (i);
}

static void	ft_puthex(unsigned long int n, int b)
{
	if (--b > 0)
		ft_puthex(n / 16, b);
	ft_putchar(BASE_HEX[n % 16]);
}

int	ft_print_pointer(t_opt *opt, va_list args)
{
	int					bytes;
	int					digits;
	unsigned long int	n;

	n = va_arg(args, unsigned long int);
	digits = ft_hex_size(n);
	if (digits < opt->precision)
		digits = opt->precision;
	if (opt->flags & PRECISION)
		opt->flags &= ~ZERO;
	bytes = digits;
	if (opt->flags & PRECISION && opt->precision == 0 && n == 0)
		bytes = 0;
	bytes += 2;
	while ((opt->flags & MIN_WIDTH) && opt->min_width > bytes)
		bytes += write(opt->fd, " ", 1);
	write(opt->fd, "0x", 2);
	while ((opt->flags & ZERO) && opt->min_width > bytes)
		bytes += write(opt->fd, "0", 1);
	if (!(opt->flags & PRECISION && opt->precision == 0 && n == 0))
		ft_puthex(n, digits);
	while ((opt->flags & DASH) && opt->min_width > bytes)
		bytes += write(opt->fd, " ", 1);
	return (bytes);
}
