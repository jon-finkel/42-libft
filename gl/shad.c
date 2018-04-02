/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:43:45 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/02 21:06:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/hdl.h"
#include "libft/gl.h"
#include "libft/io.h"
#include <fcntl.h>

#define BUFF_SIZE 128

t_shader			*ftgl_read_shader(const char *path)
{
	char			buff[BUFF_SIZE];
	int				fd;
	ssize_t			bytes;
	t_dstr			*dstr;
	t_shader		*shader;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_errhdl(NULL, 0, ERR_OPEN);
	shader = (t_shader *)ft_wralloc(sizeof(t_shader));
	dstr = (t_dstr *)ft_memalloc(sizeof(t_dstr));
	ft_memset(buff, '\0', BUFF_SIZE);
	while ((bytes = ft_read(fd, buff, BUFF_SIZE)))
	{
		ft_dstrncpush(dstr, buff, bytes);
		ft_memset(buff, '\0', BUFF_SIZE);
	}
	if (close(fd) == -1)
		ft_errhdl(NULL, 0, ERR_CLOSE);
	shader->dstr = dstr;
	shader->path = path;
	shader->source = dstr->buff;
	GIMME(shader);
}
