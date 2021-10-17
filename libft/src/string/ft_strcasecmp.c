/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:03:20 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/30 18:06:35 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(char const *s1, char const *s2)
{
	unsigned char const	*b1;
	unsigned char const	*b2;

	b1 = (unsigned char const *)s1;
	b2 = (unsigned char const *)s2;
	while (*b1 && *b2 && ft_tolower(*b1) == ft_tolower(*b2))
	{
		++b1;
		++b2;
	}
	return (*b1 - *b2);
}
