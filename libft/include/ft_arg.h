/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 00:39:51 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 01:31:09 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARG_H
# define FT_ARG_H

# include "ft_def.h"

typedef enum e_limit
{
	LIMIT_ERROR,
	LIMIT_INBOUND,
	LIMIT_OVERFLOW,
	LIMIT_UNDERFLOW
}	t_limit;

t_bool	check_int(char const *arg)
		__attribute__((nonnull(1)));

t_limit	check_int_limits(char const *arg)
		__attribute__((nonnull(1)));

#endif
