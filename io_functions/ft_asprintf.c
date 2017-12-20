/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 21:48:21 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/12 21:49:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_asprintf(char **ret, const char *format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (len);
}
