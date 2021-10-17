/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 07:20:31 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 07:22:30 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_size	ft_strspn(char const *s, char const *accept)
{
	t_size	len;

	len = 0;
	while (s[len] && ft_strchr(accept, s[len]))
		++len;
	return (len);
}
