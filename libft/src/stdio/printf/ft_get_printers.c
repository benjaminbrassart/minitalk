/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_printers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:34:39 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/09 14:36:36 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_functions.h"

t_printer	*ft_get_printers(void)
{
	static t_printer	printers[] = {
	{'c', ft_print_char},
	{'s', ft_print_string},
	{'p', ft_print_pointer},
	{'d', ft_print_int},
	{'i', ft_print_int},
	{'u', ft_print_uint},
	{'x', ft_print_hex_low},
	{'X', ft_print_hex_up},
	{'\0', NULL}
	};

	return (printers);
}
