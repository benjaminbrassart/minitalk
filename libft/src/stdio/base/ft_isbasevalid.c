/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbasevalid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:03:10 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 19:21:45 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio_base.h"
#include "ft_string.h"

t_bool	ft_isbasevalid(char const *base)
{
	char const	*bptr = base;
	t_bool		valid;

	valid = true;
	while (valid && *bptr)
	{
		valid = (ft_strrchr(base, *bptr) == bptr);
		++bptr;
	}
	return (valid);
}
