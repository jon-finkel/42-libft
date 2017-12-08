/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:07 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/08 17:48:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_buffer			*initialize_buffer(char *str, size_t size, size_t *len)
{
	t_buffer		*buffer;

	EXIT_PROTECT(buffer = (t_buffer *)malloc(sizeof(t_buffer)));
	buffer->pf_buffer = str;
	buffer->pf_len = len;
	buffer->spf_size = size - 1;
	buffer->pf_type = SPRINTF;
	buffer->invalid = 0;
	buffer->non_printable = 0;
	return (buffer);
}

int						ft_vsnprintf(char *str, size_t size, const char *format,
						va_list ap)
{
	size_t			len;
	t_buffer		*buffer;
	t_list			*list;
	t_list			*tmp;

	if (!size || !format)
		return (!size ? 0 : -1);
	ft_strclr(str);
	len = 0;
	list = NULL;
	buffer = initialize_buffer(str, size, &len);
	pf_initialize_list(&list, buffer, format, ap);
	pf_buff_format(format, list, buffer);
	buffer->pf_buffer[*buffer->pf_len] = '\0';
	len -= buffer->non_printable;
	while (list)
	{
		tmp = list->next;
		free(LIST_CONTENT);
		free(list);
		list = tmp;
	}
	free(buffer);
	return ((int)len);
}
