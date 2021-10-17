/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:04:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/22 14:15:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strlcpy(char *dst, char const *src, t_size dstsize)
{
	t_size	len;
	int		nt;

	if (!(dst && src))
		return (0);
	len = ft_strlen(src);
	nt = (dstsize > 0);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	if (nt)
		*dst = 0;
	return (len);
}
