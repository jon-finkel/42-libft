/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:25:56 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:22:03 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./io_private.h"
#include "../string_functions/string_private.h"

void			ft_putendl_fd(const char *s, int fd)
{
	if (!s)
		BYEZ;
	write(fd, s, ft_strlen(s));
	ft_putchar_fd('\n', fd);
}
