/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:17:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/30 15:19:27 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char const *s1, char const *s2)
{
	unsigned char const	*b1;
	unsigned char const	*b2;

	b1 = (unsigned char const *)s1;
	b2 = (unsigned char const *)s2;
	while (*b1 && *b1 == *b2)
	{
		++b1;
		++b2;
	}
	return (*b1 - *b2);
}
