/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:23:43 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/12 15:37:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memalloc(size_t size)
{
	void		*data;
	int			k;

	FAILZ(data = malloc(size), NULL);
	k = -1;
	while ((unsigned int)++k < size)
		*((unsigned char *)data + k) = '\0';
	return (data);
}
