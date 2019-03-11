/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:16:11 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:41:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/mem.h"
#include "libft/str.h"
#include "libft/vary.h"

#define BUFF_SIZE (4096)

inline int	get_next_line(int const fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	char			*end;
	ssize_t			nb;
	static t_dstr	dstr[USHRT_MAX];

	end = NULL;
	while ((!dstr[fd].len || (end || !(end = ft_strchr(dstr[fd].buff, '\n')))))
		if (!(nb = ft_read(fd, buff, BUFF_SIZE)))
			break ;
		else if (!(end = ft_dstrncpush(dstr + fd, buff, (size_t)nb)))
			return (-1);
		else if ((end = ft_strchr(end, '\n')))
			break ;
	if (!(nb = end ? (end - dstr[fd].buff + 1) : (ssize_t)dstr[fd].len))
		return (0);
	*line = ft_malloc((size_t)(nb + (end ? 1 : 0)) * sizeof(char));
	(*line)[ft_dstrncpy(*line, dstr + fd, (size_t)nb) - (end ? 1 : 0)] = '\0';
	return (1);
}
