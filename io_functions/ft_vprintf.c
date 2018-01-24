/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:11:04 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:16:04 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./io_private.h"

int			ft_vprintf(const char *restrict format, va_list ap)
{
	GIMME(ft_vdprintf(STDOUT_FILENO, format, ap));
}
