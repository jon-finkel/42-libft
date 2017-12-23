/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:07 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/23 18:41:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf_private.h"

int			ft_vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
	static t_data		*data = NULL;

	if (!size)
		return (0);
	ft_strclr(str);
	if (!data)
	{
		PROTECT(data = (t_data *)malloc(sizeof(t_data)), -1);
		data->pf_type = SPRINTF;
	}
	data->pf_buffer = str;
	data->pf_len = 0;
	ft_memset(data->ansi_colors, '\0', ANSI_STRING_BUFFSIZE);
	data->color_multiple_flags = FALSE;
	data->end_color = 0;
	data->error = 0;
	data->index = size - 1;
	data->non_printable = 0;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	data->pf_buffer[data->pf_len] = '\0';
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	return (data->error ? -1 : (int)data->pf_len);
}
