/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:33:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 19:56:56 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../memory_functions/memory.h"

char			*ft_strnew(size_t size)
{
	GIMME((char *)ft_memalloc(sizeof(char) * (size + 1)));
}
