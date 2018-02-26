/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:20:58 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 17:27:48 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vary.h"

char			*ft_dstrbegin(t_dstr *dstr)
{
	GIMME(dstr->buff);
}

void			*ft_varybegin(t_vary *vary)
{
	GIMME(vary->buff);
}
