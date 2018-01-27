/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:16:11 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 15:01:14 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_private.h"

static char				*strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*s;
	char	*ret;

	s = ft_strnew(ft_strlen(s1) + len + 1);
	ret = s;
	while (*s1)
		*s++ = *s1++;
	while (*s2 && len--)
		*s++ = *s2++;
	free((char *)s1);
	GIMME(ret);
}

static t_list			*get_node(t_list **begin, int fd)
{
	t_list		*list;

	list = *begin;
	while (list)
	{
		if (fd == (int)list->content_size)
			GIMME(list);
		list = list->next;
	}
	list = ft_lstnew("\0", 1);
	list->content_size = fd;
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
	while (!ft_strchr(list->content, '\n') && (ret = read(fd, buff, BUFF_SIZE)))
		list->content = strnjoin(list->content, buff, ret);
	ret = 0;
	while (((char*)list->content)[ret] && ((char*)list->content)[ret] != '\n')
		++ret;
	*line = ft_strndup(list->content, ret);
	(((char*)list->content)[ret] == '\n') ? ++ret : 0;
	tmp = list->content;
	list->content = ft_strdup(tmp + ret);
	list = begin;
	free(tmp);
	if (ret)
		GIMME(1);
	KTHXBYE;
}
