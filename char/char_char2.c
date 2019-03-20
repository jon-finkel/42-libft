/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_char2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:32:35 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/20 12:57:02 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/char.h"

inline bool	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c) ? true : false);
}

inline bool	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c) ? true : false);
}

inline int	ft_toupper(int c)
{
	return (ft_islower(c) ? (c & ~(1 << 5)) : c);
}

inline int	ft_tolower(int c)
{
	return (ft_isupper(c) ? (c | 1 << 5) : c);
}
