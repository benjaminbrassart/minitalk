/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:55:08 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 14:57:44 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_functions.h"

t_printer	ft_get_printer(int chr)
{
	t_printer *const	printers = ft_get_printers();
	int					i;

	i = 0;
	while (printers[i].chr != chr && printers[i].chr)
		++i;
	return (printers[i]);
}
