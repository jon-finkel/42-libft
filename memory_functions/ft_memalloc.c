/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:23:43 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/12 21:08:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			*ft_memalloc(size_t size)
{
	void		*data;
	int			k;

	PROTECT(data = malloc(size), NULL);
	k = -1;
	while ((unsigned int)++k < size)
		*((unsigned char *)data + k) = '\0';
	return (data);
}
