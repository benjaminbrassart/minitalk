/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_def.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 14:04:45 by bbrassar          #+#    #+#             */
/*   Updated: 2021/11/18 02:02:24 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEF_H
# define FT_DEF_H

# ifdef FT_NULL
#  undef FT_NULL
# endif
# define FT_NULL ((void *)0)

typedef char				t_hh;

typedef unsigned char		t_uhh;

typedef short				t_h;

typedef unsigned short		t_uh;

typedef int					t_i;

typedef unsigned int		t_ui;

typedef long				t_l;

typedef unsigned long		t_ul;

typedef long long			t_ll;

typedef unsigned long long	t_ull;

typedef float				t_f;

typedef double				t_lf;

typedef t_ul				t_size;

typedef t_l					t_ssize;

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

#endif
