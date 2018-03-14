/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:17:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/13 22:36:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dependencies.h"

void			ft_striter(char *s, void (*f)(char *))
{
	while (*s)
	{
		f(s);
		++s;
	}
}

void			ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		k;

	k = -1;
	while (*(s + ++k))
		f((unsigned int)k, s + k);
}
