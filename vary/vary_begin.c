/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:20:58 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:51:29 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vary.h"

inline char	*ft_dstrbegin(t_dstr *dstr)
{
	return (dstr->buff);
}

inline void	*ft_varybegin(t_vary *vary)
{
	return (vary->buff);
}
