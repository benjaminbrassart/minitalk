/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 17:49:54 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/01 17:51:16 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiteri(t_list *lst, void (*f)(t_list *, unsigned int))
{
	unsigned int	i;

	if (!f)
		return ;
	i = 0;
	while (lst)
	{
		f(lst, i++);
		lst = lst->next;
	}
}
