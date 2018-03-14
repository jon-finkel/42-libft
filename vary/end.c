/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:15 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:46:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vary.h"

char			*ft_dstrend(t_dstr *dstr)
{
	GIMME(dstr->buff + dstr->len);
}

void			*ft_varyend(t_vary *vary)
{
	GIMME((char *)vary->buff + (vary->data_size * vary->len));
}
