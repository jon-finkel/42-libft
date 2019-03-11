/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_toi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:23:17 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:44:59 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"
#include "libft/mem.h"

inline size_t	ft_mtoi(const uint8_t *mem, size_t len)
{
	size_t	sum;

	sum = 0;
	while (len)
		sum += (size_t)*mem++ * ft_stnpow(16, (uint8_t)(--len * 2));
	return (sum);
}
