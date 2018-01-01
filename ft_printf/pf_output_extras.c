/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_extras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/01 11:06:41 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static void			n_conversion(t_printf *data)
{
	int		*ptr;

	ptr = (int *)va_arg(data->arg, void *);
	if (ptr)
		*ptr = (int)data->pf_len;
}

static void			v_conversion(t_printf *data)
{
	char	*buff;
	char	*var;

	var = va_arg(data->arg, char *);
	if ((buff = ft_getenv(var)))
	{
		pf_fill_buffer(data, 0, buff, E_PRINT);
		free(buff);
	}
}

const char			*pf_output_extras(t_printf *data, const char *format)
{
	if (*format == 'n')
		n_conversion(data);
	else
		v_conversion(data);
	return (format + 1);
}
