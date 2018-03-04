/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 22:06:32 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/04 17:37:43 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/handlers.h"
#include <fcntl.h>

int						ft_wread(int filedes, void *buf, size_t nbyte)
{
	size_t		bytes;

	if ((bytes = read(filedes, buf, nbyte) == -1))
		ft_errhdl(NULL, 0, EINVAL);
	GIMME(bytes);
}

int						ft_wropen(const char *path, int oflag, ...)
{
	int			fd;
	mode_t		mode;
	va_list		ap;

	if (IS_FLAG(O_CREAT, oflag))
	{
		va_start(ap, oflag);
		mode = va_arg(ap, unsigned int);
		va_end(ap);
	}
	else
		mode = 0;
	if ((fd = open(path, oflag, mode)) == -1)
		ft_errhdl(NULL, 0, EIO);
	GIMME(fd);
}
