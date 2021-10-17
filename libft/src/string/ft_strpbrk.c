/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 07:12:43 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 07:16:14 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strpbrk(char const *s, char const *accept)
{
	while (*s)
	{
		if (ft_strchr(accept, *s))
			return ((char *)s);
		++s;
	}
	return (FT_NULL);
}
