/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:16:11 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/04 17:51:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_private.h"

int				get_next_line(int const fd, char **line)
{
	char				buf[BUFF_SIZE + 1];
	char				*end;
	ssize_t				nb;
	static t_dstr		dstr[USHRT_MAX];

	end = NULL;
	while ((!dstr[fd].len || (end || !(end = ft_strchr(dstr[fd].buff, '\n')))))
		if ((nb = read(fd, buf, BUFF_SIZE)) == 0)
			NOMOAR;
		else if (nb == -1 || !(end = ft_dstrncpush(dstr + fd, buf, (size_t)nb)))
			ONOES;
		else if ((end = ft_strchr(end, '\n')))
			NOMOAR;
	if (!(nb = end ? (end - dstr[fd].buff + 1) : (ssize_t)dstr[fd].len))
		KTHXBYE;
	*line = ft_wralloc((size_t)(nb + (end ? 1 : 0)) * sizeof(char));
	(*line)[ft_dstrncpy(*line, dstr + fd, (size_t)nb) - (end ? 1 : 0)] = '\0';
	GIMME(1);
}
