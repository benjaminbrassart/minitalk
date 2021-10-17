/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:09:01 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/01 09:33:37 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrstr(char const *haystack, char const *needle)
{
	t_size const	needle_len = ft_strlen(needle);
	t_size			i;
	t_size			j;

	i = ft_strlen(haystack);
	while (i >= needle_len)
	{
		j = needle_len;
		while (j && haystack[i - j] == needle[needle_len - j])
			--j;
		if (j == 0)
			return ((char *)haystack + i - needle_len);
		--i;
	}
	return (FT_NULL);
}
