/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:08:21 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/06 09:40:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_vfprintf(FILE *restrict stream, const char *restrict format,
			va_list ap)
{
	return (ft_vdprintf(stream->_file, format, ap));
}
