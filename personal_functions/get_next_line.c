/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:24:35 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/02 20:09:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"

static struct s_file			*lst_new_link(const int fd, struct s_file *node)
{
	char		buffer[BUFF_SIZE + 1];
	ssize_t		bytes;

	PROTECT(node = (struct s_file *)malloc(sizeof(struct s_file)), NULL);
	PROTECT(node->file = (char *)malloc(sizeof(char) * BUFF_SIZE), NULL);
	node->fd = fd;
	node->next = NULL;
	if (read(fd, buffer, 0) < 0)
		return (NULL);
	while ((bytes = read(fd, buffer, BUFF_SIZE)))
	{
		if (bytes == ERROR)
			return (NULL);
		buffer[bytes] = '\0';
		PROTECT(node->begin_file = ft_strjoin(node->file, buffer), NULL);
		free(node->file);
		node->file = node->begin_file;
	}
	return (node);
}

static int						copy_line(struct s_file *node, char **line)
{
	size_t		len;

	len = 0;
	while (*(node->file + len) != '\n' && *(node->file + len) != '\0')
		++len;
	PROTECT(*line = ft_strnew(len), ERROR);
	PROTECT(ft_strncpy(*line, node->file, len), ERROR);
	node->file += len + 1;
	return (0);
}

static void						free_node(struct s_file	*node)
{
	free(node->begin_file);
	node->begin_file = NULL;
	node->file = NULL;
}

int								get_next_line(const int fd, char **line)
{
	static struct s_file		*head = NULL;
	struct s_file				*node;

	if (fd < 0 || !line)
		return (ERROR);
	if (!head)
		PROTECT(head = lst_new_link(fd, head), ERROR);
	node = head;
	while (node && fd != node->fd)
	{
		if (!node->next)
			PROTECT(node->next = lst_new_link(fd, node), ERROR);
		node = node->next;
	}
	if (!node->file || !*node->file)
	{
		free_node(node);
		return (0);
	}
	if (copy_line(node, line) == ERROR)
		return (ERROR);
	return (1);
}
