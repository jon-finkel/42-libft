/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_extras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:42 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/14 15:31:33 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			n_conversion(t_data *data)
{
	int		*ptr;

	ptr = (int *)va_arg(data->ap, void *);
	if (ptr)
		*ptr = (int)data->pf_len;
}

static void			v_conversion(t_data *data)
{
	char	*var;

	var = va_arg(data->ap, char *);
	if ((var = ft_getenv(var)))
	{
		pf_fill_buffer(data, 0, var, PRINT);
		free(var);
	}
	else
		pf_fill_buffer(data, 0, "(null)", PRINT);
}

const char			*pf_output_extras(t_data *data, const char *format)
{
	if (*format == 'n')
		n_conversion(data);
	else
		v_conversion(data);
	return (format + 1);
}
