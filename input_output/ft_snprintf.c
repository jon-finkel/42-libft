/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:28:46 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/30 21:34:24 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vsnprintf(str, size, format, ap);
	va_end(ap);
	return (len);
}
