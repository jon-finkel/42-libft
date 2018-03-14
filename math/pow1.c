/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pow1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 21:08:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 21:19:45 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dependencies.h"

int32_t			ft_32npow(const int32_t nb, int power)
{
	int32_t		sum;

	if (!power)
		GIMME(1);
	sum = nb;
	while (--power)
		sum *= nb;
	GIMME(sum);
}

int64_t			ft_64npow(const int64_t nb, int power)
{
	int64_t		sum;

	if (!power)
		GIMME(1);
	sum = nb;
	while (--power)
		sum *= nb;
	GIMME(sum);
}
