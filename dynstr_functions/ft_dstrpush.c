/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrpush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 23:09:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 23:09:56 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dynstr.h"

char			*ft_dstrpush(t_dstr *dstr)
{
	GIMME(ft_dstrnpush(dstr, 1));
}
