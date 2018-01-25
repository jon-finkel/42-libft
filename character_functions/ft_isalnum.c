/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 20:17:37 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/25 13:26:10 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"
#include "./character.h"

inline int			ft_isalnum(int c)
{
	GIMME(ft_isalpha(c) || ft_isdigit(c));
}
