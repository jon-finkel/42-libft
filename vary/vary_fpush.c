/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vary_fpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:51:28 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/15 13:40:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/vary.h"

inline char		*ft_dstrfpush(t_dstr *dstr, const char *format, ...)
{
	char		buff[4096];
	size_t		size;
	va_list		ap;

	va_start(ap, format);
	size = ft_vsnprintf(buff, 4096, format, ap);
	va_end(ap);
	return ft_dstrncpush(dstr, buff, size);
}
