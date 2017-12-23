/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:19:01 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/23 18:41:34 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static const struct s_conv		g_conv[] =
{
	{'d', &pf_output_signed, "0123456789", VOID},
	{'s', &pf_output_string, NULL, VOID},
	{'u', &pf_output_unsigned, "0123456789", VOID},
	{'p', &pf_output_pointer, "0123456789abcdef", VOID},
	{'c', &pf_output_char, NULL, VOID},
	{'i', &pf_output_signed, "0123456789", VOID},
	{'f', &pf_output_double, "0123456789", VOID},
	{'F', &pf_output_double, "0123456789", VOID},
	{'x', &pf_output_unsigned, "0123456789abcdef", VOID},
	{'X', &pf_output_unsigned, "0123456789ABCDEF", VOID},
	{'b', &pf_output_unsigned, "01", VOID},
	{'o', &pf_output_unsigned, "01234567", VOID},
	{'r', &pf_output_noprint, "0123456789abcdef", VOID},
	{'D', &pf_output_signed, "0123456789", LONG},
	{'U', &pf_output_unsigned, "0123456789", LONG},
	{'O', &pf_output_unsigned, "01234567", LONG},
	{'S', &pf_output_string, NULL, LONG},
	{'C', &pf_output_char, NULL, LONG}
};

static const char			*get_range(t_data *data, const char *format)
{
	while (*format == 'j' || *format == 'z' || *format == 'l' || *format == 'h')
	{
		if (*format == 'j' && data->range < INTMAX_T)
			data->range = INTMAX_T;
		else if (*format == 'z' && data->range < SIZE_T)
			data->range = SIZE_T;
		else if (*format == 'l' && *(format + 1) == 'l'
			&& data->range < LONG_LONG && ++format)
			data->range = LONG_LONG;
		else if (*format == 'l')
			data->range = LONG;
		else if (*format == 'h' && *(format + 1) == 'h'
			&& data->range < CHAR && ++format)
			data->range = CHAR;
		else if (*format == 'h' && data->range < SHORT)
			data->range = SHORT;
		++format;
	}
	return (format);
}

static const char			*print_conversion(t_data *data, const char *format)
{
	int		k;

	format = get_range(data, format);
	format = pf_get_flags(data, format, SECOND);
	if (!*format)
		return (format);
	if (*format == 'n' || *format == 'v')
		return (pf_output_extras(data, format));
	k = -1;
	while (++k < LAST_CONVERSION_FLAG)
		if ((unsigned char)*format == (unsigned char)g_conv[k].letter)
		{
			if (g_conv[k].range != VOID && data->range != LONG)
				data->range = g_conv[k].range;
			NEG_PROTECT(g_conv[k].f(data, g_conv[k].base), NULL);
			break ;
		}
	if (k == LAST_CONVERSION_FLAG)
	{
		data->range = CHAR;
		data->c = *format;
		pf_output_char(data, NULL);
	}
	return (format + 1);
}

void						pf_buff_format(t_data *data, const char *format)
{
	while (format && *format)
	{
		while (*format == '{')
			format = pf_ansi_color(data, format);
		if (*format && *format != '%')
			pf_fill_buffer(data, *format++, NULL, PRINT);
		else if (*format == '%' && ++format)
		{
			if (*format == '%')
				pf_fill_buffer(data, *format++, NULL, PRINT);
			else if (*format)
			{
				data->range = INT;
				ft_memset(data->ansi_colors, '\0', ANSI_STRING_BUFFSIZE);
				data->c = 0;
				data->flags = 0;
				data->field_width = 0;
				data->precision = INT_MAX;
				format = pf_get_flags(data, format, FIRST);
				if (!(format = print_conversion(data, format)))
					data->error = 1;
			}
		}
	}
}
