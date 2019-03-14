/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 22:04:24 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/14 13:41:31 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"

inline int	ft_printf(const char *restrict format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (len);
}

inline int	ft_dprintf(int fd, const char *restrict format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (len);
}

inline int	ft_fprintf(FILE *restrict stream, const char *restrict format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vfprintf(stream, format, ap);
	va_end(ap);
	return (len);
}

inline int	ft_asprintf(char **ret, const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (len);
}
