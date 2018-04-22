/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_m4iter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:43:36 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:09:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vec.h"

t_v3	**ft_v3m4iter(t_v3 **avec, const t_m4 matrix, size_t size)
{
	int	k;

	k = -1;
	while ((size_t)++k < size)
		ft_v3_m4(avec[k], matrix);
	GIMME(avec);
}

t_v4	**ft_v4m4iter(t_v4 **avec, const t_m4 matrix, size_t size)
{
	int	k;

	k = -1;
	while ((size_t)++k < size)
		ft_v4_m4(avec[k], matrix);
	GIMME(avec);
}
