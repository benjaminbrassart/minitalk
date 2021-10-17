/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:40:12 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/22 14:15:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, t_size n)
{
	unsigned char const	*b1;
	unsigned char const	*b2;

	if (n == 0)
		return (0);
	b1 = s1;
	b2 = s2;
	while (--n && *b1 == *b2)
	{
		b1++;
		b2++;
	}
	return (*b1 - *b2);
}
