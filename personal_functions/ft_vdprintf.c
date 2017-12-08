/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:02:38 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/08 17:49:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_buffer			*initialize_buffer(size_t *len)
{
	t_buffer		*buffer;

	EXIT_PROTECT(buffer = (t_buffer *)malloc(sizeof(t_buffer)));
	EXIT_PROTECT(buffer->pf_buffer = ft_strnew(PRINTF_BUFFSIZE));
	buffer->pf_len = len;
	buffer->pf_type = PRINTF;
	buffer->invalid = 0;
	buffer->non_printable = 0;
	buffer->size_factor = 1;
	return (buffer);
}

int						ft_vdprintf(int fd, const char *format, va_list ap)
{
	size_t			len;
	t_buffer		*buffer;
	t_list			*list;
	t_list			*tmp;

	if (!format)
		return (-1);
	len = 0;
	list = NULL;
	buffer = initialize_buffer(&len);
	pf_initialize_list(&list, buffer, format, ap);
	pf_buff_format(format, list, buffer);
	write(fd, buffer->pf_buffer, *buffer->pf_len);
	len -= buffer->non_printable;
	while (list)
	{
		tmp = list->next;
		free(LIST_CONTENT);
		free(list);
		list = tmp;
	}
	free(buffer->pf_buffer);
	free(buffer);
	return ((int)len);
}
