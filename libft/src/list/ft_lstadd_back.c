/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:43:41 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/16 16:38:51 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *elem)
{
	t_list	*lst;

	if (alst)
	{
		lst = ft_lstlast(*alst);
		if (lst)
			lst->next = elem;
		else
			*alst = elem;
	}
}
