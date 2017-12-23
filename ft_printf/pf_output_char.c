/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:40:40 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/23 21:23:17 by nfinkel          ###   ########.fr       */
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
		UNSET_FLAG(E_ZERO, data->flags);
	field_width = data->field_width;
	if (IS_FLAG(E_ZERO, data->flags) && IS_FLAG(E_ANSI_COLOR, data->flags))
		pf_fill_buffer(data, 0, data->ansi_colors, E_NON_PRINT);
	filler = (IS_FLAG(E_ZERO, data->flags) ? '0' : ' ');
	while (field_width-- > (data->range == E_LONG ? width : 1))
		pf_fill_buffer(data, filler, NULL, E_PRINT);
}

static int				output_wide_char(t_data *data, int c)
{
	if (c < 0 || c > 0x10ffff
		|| (MB_CUR_MAX == 1 && c > 0xff && c <= 0x10ffff)
		|| (c >= 0xd800 && c <= 0xdfff))
		return (-1);
	if (c >= 0 && (c < 128 || (MB_CUR_MAX == 1 && c <= 0x100)))
	{
		pf_fill_buffer(data, c, NULL, E_PRINT);
		return (0);
	}
	if (FOUR_BYTES_UNICODE(c))
	{
		pf_fill_buffer(data, FOUR_BYTES_UNICODE_HEAD(c), NULL, E_PRINT);
		pf_fill_buffer(data, THREE_BYTES_UNICODE_BODY(c), NULL, E_PRINT);
	}
	if (THREE_BYTES_UNICODE(c))
		pf_fill_buffer(data, THREE_BYTES_UNICODE_HEAD(c), NULL, E_PRINT);
	if (THREE_OR_MORE_BYTES_UNICODE(c))
		pf_fill_buffer(data, TWO_BYTES_UNICODE_BODY(c), NULL, E_PRINT);
	if (TWO_BYTES_UNICODE(c))
		pf_fill_buffer(data, TWO_BYTES_UNICODE_HEAD(c), NULL, E_PRINT);
	if (TWO_OR_MORE_BYTES_UNICODE(c))
		pf_fill_buffer(data, UNICODE_TAIL(c), NULL, E_PRINT);
	return (0);
}

int						pf_output_char(t_data *data, const char *base)
{
	int					field_width;
	int					width;
	wchar_t				wc;

	(void)base;
	if (data->range == E_LONG)
		wc = adjust_field_width(data, &width);
	apply_left_field_width(data, (data->range == E_LONG ? width : 1));
	if (data->range == E_LONG)
		NEG_PROTECT(output_wide_char(data, wc), -1);
	else
	{
		if (IS_NOT(E_ZERO, data->flags) && IS_FLAG(E_ANSI_COLOR, data->flags))
			pf_fill_buffer(data, 0, data->ansi_colors, E_NON_PRINT);
		if (data->range == E_CHAR)
			pf_fill_buffer(data, data->c, NULL, E_PRINT);
		else
			pf_fill_buffer(data, (char)va_arg(data->ap, int), NULL, E_PRINT);
	}
	field_width = -data->field_width;
	while (field_width-- > (data->range == E_LONG ? width : 1))
		pf_fill_buffer(data, ' ', NULL, E_PRINT);
	return (0);
}
