/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 03:10:01 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 07:22:48 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_size	ft_strcspn(char const *s, char const *reject)
{
	t_size	i;

	i = 0;
	while (!ft_strchr(reject, s[i]))
		++i;
	return (i);
}
