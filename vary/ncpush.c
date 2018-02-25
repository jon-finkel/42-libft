/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncpush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:21:03 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:20:26 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"
#include "../mem/mem.h"

char			*ft_dstrncpush(t_dstr *dstr, const char *data, size_t size)
{
	GIMME(ft_memmove(ft_dstrnpush(dstr, size), data, size * sizeof(char)));
}
