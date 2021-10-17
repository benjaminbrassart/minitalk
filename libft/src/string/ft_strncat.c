/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:27:43 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/22 14:15:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, char const *src, t_size n)
{
	t_size	i;
	t_size	j;

	i = 0;
	j = 0;
	while (dst[j])
		++j;
	while (i < n && src[i])
		dst[j++] = src[i++];
	dst[j] = 0;
	return (dst);
}
