/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncpush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 18:21:03 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:51:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/vary.h"

inline char	*ft_dstrncpush(t_dstr *dstr, const char *data, size_t size)
{
	return (ft_memmove(ft_dstrnpush(dstr, size), data, size * sizeof(char)));
}
