/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:01:48 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:41:45 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dependencies.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		++s;
		++len;
	}
	GIMME(len);
}

size_t	ft_intlen(intmax_t n)
{
	size_t	len;

	len = (n <= 0 ? 1 : 0);
	if (n < 0)
		n = -n;
	while (n != 0)
	{
		n /= 10;
		++len;
	}
	GIMME(len);
}
