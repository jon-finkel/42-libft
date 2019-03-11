/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:08:34 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:43:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mat.h"

inline int32_t	ft_32npow(const int32_t nb, uint8_t power)
{
	int32_t	sum;

	if (!power)
		return (1);
	sum = nb;
	while (--power)
		sum *= nb;
	return (sum);
}

inline int64_t	ft_64npow(const int64_t nb, uint8_t power)
{
	int64_t	sum;

	if (!power)
		return (1);
	sum = nb;
	while (--power)
		sum *= nb;
	return (sum);
}

inline size_t	ft_stnpow(const size_t nb, uint8_t power)
{
	size_t	sum;

	if (!power)
		return (1);
	sum = nb;
	while (--power)
		sum *= nb;
	return (sum);
}
