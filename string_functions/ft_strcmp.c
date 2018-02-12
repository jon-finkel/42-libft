/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:56:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:25:14 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

int			ft_strcmp(const char *restrict s1, const char *restrict s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	GIMME((unsigned char)*s1 - (unsigned char)*s2);
}
