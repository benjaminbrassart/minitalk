/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:20:21 by bbrassar          #+#    #+#             */
/*   Updated: 2021/08/02 17:01:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(void const *s, int c, t_size n)
{
	unsigned char const	*b;
	unsigned char		ch;

	b = s;
	ch = c;
	while (n--)
		if (b[n] == ch)
			return ((void *)b + n);
	return (FT_NULL);
}
