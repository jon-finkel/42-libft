/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:20:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:25:33 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

void			ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		k;

	k = -1;
	while (*(s + ++k))
		f((unsigned int)k, s + k);
}
