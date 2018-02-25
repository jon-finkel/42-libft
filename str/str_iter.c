/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:17:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:27:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

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
