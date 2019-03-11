/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:33:06 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:50:03 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/str.h"

inline char	*ft_strctor(size_t size)
{
	return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
}
