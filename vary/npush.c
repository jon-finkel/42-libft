/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:46:42 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vary.h"

char			*ft_dstrnpush(t_dstr *dstr, size_t size)
{
	char		*str;

	ft_dstrgrow(dstr, size);
	str = ft_dstrend(dstr);
	dstr->len += size;
	str[size] = '\0';
	GIMME(str);
}

void			*ft_varynpush(t_vary *vary, size_t size)
{
	void		*ptr;

	ft_varygrow(vary, size);
	ptr = ft_varyend(vary);
	vary->len += size;
	GIMME(ptr);
}
