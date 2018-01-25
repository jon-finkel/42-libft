/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:49:26 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/25 13:26:27 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"
#include "./character.h"

inline int			ft_toupper(int c)
{
	GIMME(ft_islower(c) ? (c & ~(1 << 5)) : c);
}
