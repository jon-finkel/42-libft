/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:07:16 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/06 09:13:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_printf(const char *restrict format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (len);
}
