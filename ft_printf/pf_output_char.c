/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:40:40 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/15 19:45:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static wchar_t			adjust_field_width(t_data *data, int *width)
{
	wchar_t		wc;

	wc = va_arg(data->ap, wchar_t);
	if (FOUR_BYTES_UNICODE(wc))
		*width = 4;
	else if (THREE_BYTES_UNICODE(wc))
		*width = 3;
	else if (TWO_BYTES_UNICODE(wc))
		*width = 2;
	else
		*width = 1;
	return (wc);
}

static void				apply_left_field_width(t_data *data, int width)
{
	char	filler;
	int		field_width;

	if (data->field_width < 0)
		UNSET_FLAG(ZERO, data->flags);
	field_width = data->field_width;
	filler = (IS_FLAG(ZERO, data->flags) ? '0' : ' ');
	while (field_width-- > (data->range == LONG ? width : 1))
		pf_fill_buffer(data, filler, NULL, PRINT);
}

static int				output_wide_char(t_data *data, int c)
{
	if (c < 0 || c > 0x10ffff
		|| (MB_CUR_MAX == 1 && c > 0xff && c <= 0x10ffff)
		|| (c >= 0xd800 && c <= 0xdb7f) || (c >= 0xdb80 && c < 0xdbff))
		return (-1);
	if (c >= 0 && c < 128)
		pf_fill_buffer(data, c, NULL, PRINT);
	if (FOUR_BYTES_UNICODE(c))
	{
		pf_fill_buffer(data, FOUR_BYTES_UNICODE_HEAD(c), NULL, PRINT);
		pf_fill_buffer(data, THREE_BYTES_UNICODE_BODY(c), NULL, PRINT);
	}
	if (THREE_BYTES_UNICODE(c))
		pf_fill_buffer(data, THREE_BYTES_UNICODE_HEAD(c), NULL, PRINT);
	if (THREE_OR_MORE_BYTES_UNICODE(c))
		pf_fill_buffer(data, TWO_BYTES_UNICODE_BODY(c), NULL, PRINT);
	if (TWO_BYTES_UNICODE(c))
		pf_fill_buffer(data, TWO_BYTES_UNICODE_HEAD(c), NULL, PRINT);
	if (TWO_OR_MORE_BYTES_UNICODE(c))
		pf_fill_buffer(data, UNICODE_TAIL(c), NULL, PRINT);
	return (0);
}

int						pf_output_char(t_data *data, const char *base)
{
	int					field_width;
	int					width;
	wchar_t				wc;

	(void)base;
	if (data->range == LONG)
		wc = adjust_field_width(data, &width);
	apply_left_field_width(data, (data->range == LONG ? width : 1));
	if (data->range == LONG)
		NEG_PROTECT(output_wide_char(data, wc), -1);
	else
	{
		if (data->range == CHAR)
			pf_fill_buffer(data, data->c, NULL, PRINT);
		else
			pf_fill_buffer(data, (char)va_arg(data->ap, int), NULL, PRINT);
	}
	field_width = -data->field_width;
	while (field_width-- > (data->range == LONG ? width : 1))
		pf_fill_buffer(data, ' ', NULL, PRINT);
	return (0);
}
