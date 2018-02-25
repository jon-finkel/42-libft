/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:02:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 09:44:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf_private.h"

int			ft_vdprintf(int fd, const char *restrict format, va_list ap)
{
	char			buff[PRINTF_BUFFSIZE + 1];
	int				ret_printf;
	t_printf		*data;

	data = (t_printf *)ft_memalloc(sizeof(t_printf));
	data->pf_type = E_PRINTF;
	data->pf_buffer = buff;
	data->fd = fd;
	data->positional = E_UNDEFINED;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	write(fd, data->pf_buffer, data->index);
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	if (data->positional == E_NON_POSITIONAL)
		va_end(data->arg);
	ret_printf = (data->error ? -1 : (int)data->pf_len);
	ft_memdel((void **)&data);
	GIMME(ret_printf);
}
