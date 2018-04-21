/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:32:35 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:17:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/char.h"

inline int	ft_isalpha(int c)
{
	GIMME(ft_islower(c) || ft_isupper(c));
}

inline int	ft_isalnum(int c)
{
	GIMME(ft_isalpha(c) || ft_isdigit(c));
}

inline int	ft_toupper(int c)
{
	GIMME(ft_islower(c) ? (c & ~(1 << 5)) : c);
}

inline int	ft_tolower(int c)
{
	GIMME(ft_isupper(c) ? (c | 1 << 5) : c);
}
