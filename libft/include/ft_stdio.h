/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:12:35 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/17 22:52:27 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdarg.h>

/**
 * Write a character to stdout
 * 
 * @param c the character to write
 * @return -1 if an error occurred, 1 otherwise
 */
int		ft_putc(int c);

/**
 * Write a character to a specific file descriptor
 * 
 * @param fd the file descriptor
 * @param c the character to write
 * @return -1 if an error occurred, 1 otherwise
 */
int		ft_dputc(int fd, int c);

/**
 * Write a string to stdout
 * 
 * @param s the string to write
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_puts(char const *s)
		__attribute__((nonnull(1)));

/**
 * Write a string to a specific file descriptor
 * 
 * @param fd the file descriptor
 * @param s the string to write
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_dputs(int fd, char const *s)
		__attribute__((nonnull(2)));

/**
 * Write a string followed by a new line to stdout
 * 
 * @param s the string to write
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_putnl(char const *s)
		__attribute__((nonnull(1)));

/**
 * Write a string followed by a new line to a specific file descriptor
 * 
 * @param fd the file descriptor
 * @param s the string to write
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_dputnl(int fd, char const *s)
		__attribute__((nonnull(2)));

/**
 * Write a signed number to stdout
 * 
 * @param n the number to write
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_puti(int n);

/**
 * Write a signed number to a specific file descriptor
 * 
 * @param fd the file descriptor
 * @param n the number to write
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_dputi(int fd, int n);

/**
 * Write an unsigned number to stdout
 * 
 * @param n the number to write
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_putui(unsigned int n);

/**
 * Write an unsigned number to a specific file descriptor
 * 
 * @param fd the file descriptor
 * @param n the number to write
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_dputui(int fd, unsigned int n);

/**
 * Write an unsigned number in a specific base to stdout
 * 
 * @param n the number to write
 * @param base the base to format the number in
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_putub(unsigned int n, char const *base)
		__attribute__((nonnull(2)));

/**
 * Write an unsigned number in a specific base to a specific file descriptor
 * 
 * @param fd the file descriptor
 * @param n the number to write
 * @param base the base to format the number in
 * @return -1 if an error occurred, the number of written characters otherwise
 */
int		ft_dputub(int fd, unsigned int n, char const *base)
		__attribute__((nonnull(3)));

void	ft_putchar(char c)
		__attribute__((deprecated("use ft_putc() otherwise")));

void	ft_putchar_fd(char c, int fd)
		__attribute__((deprecated("use ft_dputc() otherwise")));

void	ft_putstr(char const *s)
		__attribute__((deprecated("use ft_puts() otherwise")));

void	ft_putstr_fd(char const *s, int fd)
		__attribute__((deprecated("use ft_dputs() otherwise")));

void	ft_putendl(char const *s);

void	ft_putendl_fd(char const *s, int fd);

void	ft_putnbr(int n)
		__attribute__((deprecated("use ft_puti() otherwise")));

void	ft_putnbr_fd(int n, int fd)
		__attribute__((deprecated("use ft_dputi() otherwise")));

int		ft_printf(char const *fmt, ...)
		__attribute__((format(printf, 1, 2)));

int		ft_dprintf(int fd, char const *fmt, ...)
		__attribute__((format(printf, 2, 3)));

int		ft_vprintf(char const *fmt, va_list args);

int		ft_vdprintf(int fd, char const *fmt, va_list args);

#endif
