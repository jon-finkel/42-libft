/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrnpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 23:07:35 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 23:09:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dynstr.h"

char			*ft_dstrnpush(t_dstr *dstr, size_t size)
{
	ft_dstrgrow(dstr, size);
	dstr->len += size;
	GIMME(ft_dstrend(dstr));
}
