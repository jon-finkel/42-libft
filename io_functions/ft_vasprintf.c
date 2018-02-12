/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:01:21 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf_private.h"

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	static t_printf		*data = NULL;

	if (!data)
	{
		data = (t_printf *)ft_memalloc(sizeof(t_printf));
		data->pf_type = E_ASPRINTF;
	}
	data->pf_buffer = ft_strnew(ASPRINTF_BUFFSIZE);
	data->pf_len = 0;
	data->pf_max_len = ASPRINTF_BUFFSIZE;
	ft_memset(data->ansi_colors, '\0', ANSI_STRING_BUFFSIZE);
	data->error = 0;
	data->non_printable = 0;
	data->positional = E_UNDEFINED;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	*ret = data->pf_buffer;
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	if (data->positional == E_NON_POSITIONAL)
		va_end(data->arg);
	GIMME(data->error ? -1 : (int)data->pf_len);
}
