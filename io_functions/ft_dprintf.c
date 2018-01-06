/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:09:30 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/06 09:09:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (len);
}
