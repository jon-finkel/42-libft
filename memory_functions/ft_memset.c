/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:48:10 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/11 08:45:26 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

void			*ft_memset(void *b, int c, size_t len)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < len)
		*((unsigned char *)b + k) = (unsigned char)c;
	GIMME(b);
}
