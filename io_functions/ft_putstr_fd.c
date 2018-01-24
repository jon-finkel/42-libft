/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:21:59 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:18:24 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string_functions/string_private.h"

void			ft_putstr_fd(const char *restrict s, int fd)
{
	if (!s)
		BYEZ;
	write(fd, s, ft_strlen(s));
}
