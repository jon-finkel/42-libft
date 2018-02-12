/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:16:11 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:18:59 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_private.h"

static char				*strnjoin(const char *restrict s1,
						const char *restrict s2, size_t len)
{
	char	*s;
	char	*ret;
	char	*tmp;

	s = ft_strnew(ft_strlen(s1) + len + 1);
	ret = s;
	tmp = (char *)s1;
	while (*s1)
		*s++ = *s1++;
	while (*s2 && len--)
		*s++ = *s2++;
	free(tmp);
	GIMME(ret);
}

static t_list			*get_node(t_list **begin, int fd)
{
	t_list		*list;

	list = *begin;
	while (list)
	{
		if (fd == (int)list->data_size)
			GIMME(list);
		list = list->next;
	}
	list = ft_lstnew("\0", 1);
	list->data_size = fd;
	ft_lstadd(begin, list);
	GIMME(list);
}

int						get_next_line(int const fd, char **line)
{
	char				buff[BUFF_SIZE + 1];
	int					ret;
	static t_list		*list;
	t_list				*begin;
	char				*tmp;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		ONOES;
	begin = list;
	list = get_node(&begin, fd);
	while (!ft_strchr(list->data, '\n') && (ret = read(fd, buff, BUFF_SIZE)))
		list->data = strnjoin(list->data, buff, ret);
	ret = 0;
	while (((char*)list->data)[ret] && ((char*)list->data)[ret] != '\n')
		++ret;
	*line = ft_strndup(list->data, ret);
	if (((char*)list->data)[ret] == '\n')
		++ret;
	tmp = list->data;
	list->data = ft_strdup(tmp + ret);
	list = begin;
	free(tmp);
	GIMME(ret ? 1 : 0);
}
