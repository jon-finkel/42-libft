/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 09:46:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf_private.h"

int			ft_vsnprintf(char *restrict str, size_t size,
			const char *restrict format, va_list ap)
{
	int				ret_printf;
	t_printf		*data;

	if (!size)
		KTHXBYE;
	ft_memset(str, '\0', size);
	data = (t_printf *)ft_memalloc(sizeof(t_printf));
	data->pf_type = E_SPRINTF;
	data->pf_buffer = str;
	data->index = size - 1;
	data->positional = E_UNDEFINED;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	data->pf_buffer[data->pf_len] = '\0';
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	if (data->positional == E_NON_POSITIONAL)
		va_end(data->arg);
	ret_printf = (data->error ? -1 : (int)data->pf_len);
	ft_memdel((void **)&data);
	GIMME(ret_printf);
}
