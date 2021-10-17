/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:07:25 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/22 14:15:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncasecmp(char const *s1, char const *s2, t_size n)
{
	unsigned char const	*b1;
	unsigned char const	*b2;

	b1 = (unsigned char const *)s1;
	b2 = (unsigned char const *)s2;
	if (n == 0)
		return (0);
	while (*b1 && *b2 && ft_tolower(*b1) == ft_tolower(*b2) && --n)
	{
		++b1;
		++b2;
	}
	return (*b1 - *b2);
}
