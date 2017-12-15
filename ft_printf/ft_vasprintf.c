/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:07 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/15 19:43:51 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	static t_data		*data = NULL;

	if (!ret)
		return (0);
	if (!data)
	{
		PROTECT(data = (t_data *)malloc(sizeof(t_data)), -1);
		data->pf_type = ASPRINTF;
	}
	PROTECT(data->pf_buffer = ft_strnew(ASPRINTF_BUFFSIZE), -1);
	data->pf_len = 0;
	data->realloc_factor = 1;
	data->error = 0;
	data->non_printable = 0;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	*ret = data->pf_buffer;
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	return (data->error ? -1 : (int)data->pf_len);
}
