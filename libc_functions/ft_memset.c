/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 22:48:10 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 12:07:36 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	char		*s;
	int			k;

	s = (char *)b;
	k = -1;
	while ((unsigned int)++k < len)
		*(s + k) = (unsigned char)c;
	return (b);
}
