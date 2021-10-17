/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:12:03 by bbrassar          #+#    #+#             */
/*   Updated: 2021/08/02 17:01:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s, char const *set)
{
	t_size	i;

	if (!(s && set))
		return (FT_NULL);
	while (*s && ft_strchr(set, *s))
		++s;
	i = ft_strlen(s);
	if (i-- == 0)
		return (ft_strdup(""));
	while (ft_strchr(set, s[i]))
		--i;
	return (ft_substr(s, 0, i + 1));
}
