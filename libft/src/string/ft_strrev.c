/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:38:58 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/22 14:15:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	t_size	i;
	t_size	n;
	char	*str;

	i = 0;
	n = ft_strlen(s);
	str = ft_calloc(n + 1, sizeof (char));
	if (str)
	{
		while (i++ < n)
		{
			str[n - i] = s[i];
			++i;
		}
	}
	return (str);
}
