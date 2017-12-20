/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:48:10 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/12 21:08:29 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	int			k;

	k = -1;
	while ((unsigned int)++k < len)
		*((unsigned char *)b + k) = (unsigned char)c;
	return (b);
}
