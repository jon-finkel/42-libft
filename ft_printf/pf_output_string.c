/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:46:19 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/15 19:46:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static size_t			get_wide_length(t_data *data, const wchar_t *s)
{
	size_t				len;
	unsigned int		precision;

	len = 0;
	precision = 0;
	while (*s)
	{
		if ((int)(*s) >= 0 && (int)(*s) < 128 && ++len)
			if ((int)len <= data->precision)
				precision += 1;
		if (FOUR_BYTES_UNICODE((int)(*s)) && (len += 4))
			if ((int)len <= data->precision)
				precision += 4;
		if (THREE_BYTES_UNICODE((int)(*s)) && (len += 3))
			if ((int)len <= data->precision)
				precision += 3;
		if (TWO_BYTES_UNICODE((int)(*s)) && (len += 2))
			if ((int)len <= data->precision)
				precision += 2;
		++s;
	}
	data->precision = precision;
	return (len);
}

static int				copy_wide_string(const wchar_t *w, char *s)
{
	while (*w)
	{
		if (*w < 0 || *w > 0x10ffff
			|| (MB_CUR_MAX == 1 && *w > 0xff && *w <= 0x10ffff)
			|| (*w >= 0xd800 && *w <= 0xdb7f) || (*w >= 0xdb80 && *w < 0xdbff))
			return (-1);
		if (*w >= 0 && *w < 128)
			*s++ = *w;
		if (FOUR_BYTES_UNICODE(*w))
		{
			*s++ = FOUR_BYTES_UNICODE_HEAD(*w);
			*s++ = THREE_BYTES_UNICODE_BODY(*w);
		}
		if (THREE_BYTES_UNICODE(*w))
			*s++ = THREE_BYTES_UNICODE_HEAD(*w);
		if (THREE_OR_MORE_BYTES_UNICODE(*w))
			*s++ = TWO_BYTES_UNICODE_BODY(*w);
		if (TWO_BYTES_UNICODE(*w))
			*s++ = TWO_BYTES_UNICODE_HEAD(*w);
		if (TWO_OR_MORE_BYTES_UNICODE(*w))
			*s++ = UNICODE_TAIL(*w);
		++w;
	}
	return (0);
}

static void				apply_left_field_width(t_data *data, int precision)
{
	char		filler;
	int			field_width;

	if (data->field_width < 0)
		UNSET_FLAG(ZERO, data->flags);
	filler = (IS_FLAG(ZERO, data->flags) ? '0' : ' ');
	field_width = data->field_width;
	while (field_width-- > precision)
		pf_fill_buffer(data, filler, NULL, PRINT);
}

static void				apply_precision(t_data *data, char *string,
						int precision)
{
	char		adjusted_string[precision + 1];
	int			field_width;
	int			k;

	k = -1;
	while (++k < precision)
		adjusted_string[k] = string[k];
	adjusted_string[precision] = '\0';
	pf_fill_buffer(data, 0, adjusted_string, PRINT);
	field_width = -data->field_width;
	while (field_width-- > precision)
		pf_fill_buffer(data, ' ', NULL, PRINT);
}

int						pf_output_string(t_data *data, const char *base)
{
	char		*string;
	int			precision;
	wchar_t		*wide_string;

	(void)base;
	string = NULL;
	if (data->precision < 0)
		data->precision = INT_MAX;
	if (data->range == LONG && (wide_string = va_arg(data->ap, wchar_t *)))
	{
		PROTECT(string = ft_strnew(get_wide_length(data, wide_string)), -1);
		NEG_PROTECT(copy_wide_string(wide_string, string), -1);
	}
	else if (data->range != LONG)
		string = va_arg(data->ap, char *);
	string = (!string ? "(null)" : string);
	precision = MIN(data->precision, (int)ft_strlen(string));
	apply_left_field_width(data, precision);
	apply_precision(data, string, precision);
	if (data->range == LONG && wide_string)
		free(string);
	return (0);
}
