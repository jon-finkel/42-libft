/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 09:08:21 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:16:24 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./io_private.h"

int			ft_vfprintf(FILE *restrict stream, const char *restrict format,
			va_list ap)
{
	GIMME(ft_vdprintf(stream->_file, format, ap));
}
