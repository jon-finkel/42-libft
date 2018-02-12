/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:23:43 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 19:49:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./memory.h"

void			*ft_memalloc(size_t size)
{
	void		*data;
	int			k;

	data = ft_wralloc(size);
	k = -1;
	while ((unsigned int)++k < size)
		*((unsigned char *)data + k) = '\0';
	GIMME(data);
}
