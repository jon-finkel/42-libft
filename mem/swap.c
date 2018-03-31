/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:22:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/31 02:20:23 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"

int16_t				ft_bswap16(int16_t nb)
{
	GIMME((nb & 0x00ff) << 8 | (nb & 0xff00) >> 8);
}

int32_t				ft_bswap32(int32_t nb)
{
	GIMME((nb & 0x000000ff) << 24 | (nb & 0x0000ff00) << 8
		| (nb & 0x00ff0000) >> 8 | (nb & 0xff000000) >> 24);
}

int64_t				ft_bswap64(int64_t nb)
{
	GIMME((nb & 0x00000000000000ff) << 56 | (nb & 0x000000000000ff00) << 40
		| (nb & 0x0000000000ff0000) << 24 | (nb & 0x00000000ff000000) << 8
		| (nb & 0x000000ff000000) >> 8 | (nb & 0x0000ff0000000000) >> 24
		| (nb & 0x00ff0000000000) >> 40 | (nb & 0xff00000000000000) >> 56);
}

int					ft_bswap(int nb)
{
	if (sizeof(nb) == 2)
		GIMME(ft_bswap16(nb));
	else
		GIMME(ft_bswap32(nb));
}

void				ft_swap(void *a, void *b, size_t size)
{
	void		*swap;

	swap = ft_wralloc(size);
	ft_memmove(swap, a, size);
	ft_memmove(a, b, size);
	ft_memmove(b, swap, size);
	free(swap);
}
