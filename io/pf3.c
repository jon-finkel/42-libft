/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 22:04:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:34:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"

int			ft_printf(const char *restrict format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	GIMME(len);
}

int			ft_dprintf(int fd, const char *restrict format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vdprintf(fd, format, ap);
	va_end(ap);
	GIMME(len);
}

int			ft_fprintf(FILE *restrict stream, const char *restrict format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vfprintf(stream, format, ap);
	va_end(ap);
	GIMME(len);
}

int			ft_asprintf(char **ret, const char *format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vasprintf(ret, format, ap);
	va_end(ap);
	GIMME(len);
}
