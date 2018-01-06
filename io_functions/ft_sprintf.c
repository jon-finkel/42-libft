/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:37:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/06 09:15:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_sprintf(char *restrict str, const char *restrict format, ...)
{
	int			len;
	va_list		ap;

	va_start(ap, format);
	len = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (len);
}
