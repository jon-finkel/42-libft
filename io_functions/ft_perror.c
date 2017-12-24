/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/24 18:53:52 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/24 19:35:07 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_perror(const char *s, ...)
{
	va_list		ap;

	va_start(ap, s);
	ft_vdprintf(STDERR_FILENO, s, ap);
	va_end(ap);
}
