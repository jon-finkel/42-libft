/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:22:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:15:41 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mem.h"

void			ft_swap(void *a, void *b, size_t size)
{
	void		*swap;

	swap = ft_wralloc(size);
	ft_memmove(swap, a, size);
	ft_memmove(a, b, size);
	ft_memmove(b, swap, size);
	free(swap);
}
