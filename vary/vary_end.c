/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:15 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:51:40 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vary.h"

inline char	*ft_dstrend(t_dstr *dstr)
{
	return (dstr->buff + dstr->len);
}

inline void	*ft_varyend(t_vary *vary)
{
	return ((char *)vary->buff + (vary->data_size * vary->len));
}
