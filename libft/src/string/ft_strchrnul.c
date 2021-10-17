/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 07:30:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 07:32:33 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strchrnul(char const *s, int c)
{
	unsigned char const	ch = c;

	while (*s && *s != ch)
		++s;
	return ((char *)s);
}
