/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 13:45:49 by bbrassar          #+#    #+#             */
/*   Updated: 2021/08/02 17:01:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, t_size n)
{
	unsigned char		*d;
	unsigned char const	*s;
	unsigned char		ch;

	d = dst;
	s = src;
	ch = c;
	while (n--)
	{
		*d++ = *s;
		if (*s++ == ch)
			return (d);
	}
	return (FT_NULL);
}
