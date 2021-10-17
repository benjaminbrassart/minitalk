/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:59:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/10 18:00:47 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

int	ft_isalpha(int c);

int	ft_isalnum(int c);

int	ft_isascii(int c);

int	ft_iscntrl(int c);

int	ft_isdigit(int c);

int	ft_isgraph(int c);

int	ft_islower(int c);

int	ft_isprint(int c);

int	ft_isspace(int c);

int	ft_isupper(int c);

int	ft_isxdigit(int c);

int	ft_tolower(int c);

int	ft_toupper(int c);

#endif