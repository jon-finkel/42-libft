/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 17:21:29 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:51:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/vary.h"

inline char	*ft_dstrpush(t_dstr *dstr)
{
	return (ft_dstrnpush(dstr, 1));
}

inline void	*ft_varypush(t_vary *vary)
{
	return (ft_varynpush(vary, 1));
}
