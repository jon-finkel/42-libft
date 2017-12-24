/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:02:38 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/24 10:06:26 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf_private.h"

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	char				buff[PRINTF_BUFFSIZE + 1];
	static t_data		*data = NULL;

	if (!data)
	{
		PROTECT(data = (t_data *)malloc(sizeof(t_data)), -1);
		data->pf_type = E_PRINTF;
	}
	data->pf_buffer = buff;
	data->pf_len = 0;
	data->fd = fd;
	ft_memset(data->ansi_colors, '\0', ANSI_STRING_BUFFSIZE);
	data->error = 0;
	data->index = 0;
	data->non_printable = 0;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	write(fd, data->pf_buffer, data->index);
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	return (data->error ? -1 : (int)data->pf_len);
}
