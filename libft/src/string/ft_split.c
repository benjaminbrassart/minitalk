/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:19:42 by bbrassar          #+#    #+#             */
/*   Updated: 2021/08/02 17:01:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	*ft_split_clear(char **split)
{
	t_size	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (FT_NULL);
}

static char	**ft_split_init(char const *s, char c, t_size *sz)
{
	if (!s)
		return (FT_NULL);
	*sz = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			++(*sz);
		++s;
	}
	return (ft_calloc(*sz + 1, sizeof (char *)));
}

char	**ft_split(char const *s, char c)
{
	t_size	sz;
	t_size	i;
	t_size	j;
	char	**split;

	split = ft_split_init(s, c, &sz);
	if (!split)
		return (FT_NULL);
	i = 0;
	while (i < sz)
	{
		j = 0;
		while (*s == c)
			++s;
		while (s[j] && s[j] != c)
			++j;
		split[i] = ft_substr(s, 0, j);
		if (split[i++] == FT_NULL)
			return (ft_split_clear(split));
		s += j;
	}
	split[sz] = FT_NULL;
	return (split);
}
