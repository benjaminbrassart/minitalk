/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:12:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/10/17 07:00:56 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdarg.h>

void	ft_putchar(char c);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr(char const *s);

void	ft_putstr_fd(char const *s, int fd);

void	ft_putendl(char const *s);

void	ft_putendl_fd(char const *s, int fd);

void	ft_putnbr(int n);

void	ft_putnbr_fd(int n, int fd);

int		ft_printf(char const *fmt, ...)
		__attribute__((format(printf, 1, 2)));

int		ft_dprintf(int fd, char const *fmt, ...)
		__attribute__((format(printf, 2, 3)));

int		ft_vprintf(char const *fmt, va_list args);

int		ft_vdprintf(int fd, char const *fmt, va_list args);

#endif
