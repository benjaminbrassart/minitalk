/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 11:17:27 by bbrassar          #+#    #+#             */
/*   Updated: 2021/08/02 17:01:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*str;
	t_size	n;

	if (!s)
		return (FT_NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	s += start;
	n = ft_strlen(s);
	if (n > len)
		n = len;
	str = ft_calloc(++n, sizeof (char));
	if (str)
		ft_strlcpy(str, s, n);
	return (str);
}
