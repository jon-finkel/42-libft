/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interceptor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:48:03 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/26 20:00:43 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_interceptor(void (*handler)(int), int total, ...)
{
	int			signo;
	va_list		ap;

	va_start(ap, total);
	while (total--)
	{
		signo = va_arg(ap, int);
		signal(signo, handler);
	}
	va_end(ap);
}
