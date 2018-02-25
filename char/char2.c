/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:32:35 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 21:35:39 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./char.h"

int			ft_isalpha(int c)
{
	GIMME(ft_islower(c) || ft_isupper(c));
}

int			ft_isalnum(int c)
{
	GIMME(ft_isalpha(c) || ft_isdigit(c));
}

int			ft_toupper(int c)
{
	GIMME(ft_islower(c) ? (c & ~(1 << 5)) : c);
}

int			ft_tolower(int c)
{
	GIMME(ft_isupper(c) ? (c | 1 << 5) : c);
}
