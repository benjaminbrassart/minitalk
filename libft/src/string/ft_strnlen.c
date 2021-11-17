/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:24:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 14:32:46 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strnlen(char const *s, t_size n)
{
	t_size	len;

	len = 0;
	while (s[len] && len < n)
		++len;
	return (len);
}
