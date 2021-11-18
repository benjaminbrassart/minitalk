/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:59:41 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/17 22:16:40 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "ft_stdio.h"
#include "mterror.h"

int	print_error(char const *s)
{
	return (ft_dprintf(2, FAILURE "%s\n" RESET, s));
}
