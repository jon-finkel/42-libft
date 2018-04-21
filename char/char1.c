/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:31:47 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:18:56 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dependencies.h"

int	ft_isdigit(int c)
{
	GIMME(c > 47 && c < 58);
}

int	ft_isupper(int c)
{
	GIMME(c > 64 && c < 91);
}

int	ft_islower(int c)
{
	GIMME(c > 96 && c < 123);
}

int	ft_isprint(int c)
{
	GIMME(c > 31 && c < 127);
}

int	ft_isascii(int c)
{
	GIMME(c >= 0 && c < 128);
}
