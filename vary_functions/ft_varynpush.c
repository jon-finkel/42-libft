/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varynpush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 09:12:19 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 09:12:21 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"

void			*ft_varynpush(t_vary *vary, size_t size)
{
	void		*ptr;

	ft_varygrow(vary, size);
	ptr = ft_varyend(vary);
	vary->len += size;
	GIMME(ptr);
}
