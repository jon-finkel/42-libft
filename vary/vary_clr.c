/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vary_clr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:04 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 17:21:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"

void			ft_varyclr(t_vary *vary, t_vdtor vdtor, ...)
{
	char		*ptr;
	va_list		ap;
	va_list		cpy;

	va_start(ap, vdtor);
	if (vary->buff)
	{
		ptr = (char *)ft_varybegin(vary) - vary->data_size;
		while ((ptr += vary->data_size) != (char *)ft_varyend(vary))
		{
			va_copy(cpy, ap);
			vdtor(ptr, ap);
			va_end(cpy);
		}
		vary->len = 0;
	}
	va_end(ap);
}
