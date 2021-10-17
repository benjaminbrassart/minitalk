/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:59:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 07:02:43 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_options.h"
#include "libft.h"
#include <stdlib.h>

static void	ft_parse_flags(char const **p_format, t_opt *opt)
{
	while (**p_format)
	{
		if (**p_format == '-')
			opt->flags |= DASH;
		else if (**p_format == '0')
			opt->flags |= ZERO;
		else if (**p_format == ' ')
			opt->flags |= SPACE;
		else if (**p_format == '+')
			opt->flags |= PLUS;
		else if (**p_format == '#')
			opt->flags |= HASHTAG;
		else
			break ;
		++(*p_format);
	}
}

static void	ft_parse_min_width(char const **p_format, va_list args, t_opt *opt)
{
	if (**p_format == '*')
	{
		opt->min_width = va_arg(args, int);
		++(*p_format);
	}
	else if (ft_isdigit(**p_format))
		opt->min_width = ft_patoi(p_format);
	else
		return ;
	opt->flags |= MIN_WIDTH;
}

static void	ft_parse_precision(char const **p_format, va_list args, t_opt *opt)
{
	while (**p_format == '.')
	{
		opt->flags |= PRECISION;
		if (*++(*p_format) == '*')
		{
			opt->precision = va_arg(args, int);
			++(*p_format);
		}
		else
			opt->precision = ft_patoi(p_format);
	}
}

static void	check_override(t_opt *opt)
{
	if (opt->flags & DASH)
		opt->flags &= ~(MIN_WIDTH | ZERO);
	if (opt->min_width < 0)
	{
		opt->flags &= ~(MIN_WIDTH | ZERO);
		opt->flags |= DASH;
		opt->min_width *= -1;
	}
	if (opt->precision < 0)
		opt->flags &= ~PRECISION;
	if (opt->flags & PLUS)
		opt->flags &= ~SPACE;
}

t_opt	ft_parse_options(char const **p_format, va_list args)
{
	t_opt	opt;

	opt.flags = 0;
	opt.precision = 0;
	opt.min_width = 0;
	ft_parse_flags(p_format, &opt);
	ft_parse_min_width(p_format, args, &opt);
	ft_parse_precision(p_format, args, &opt);
	check_override(&opt);
	return (opt);
}
