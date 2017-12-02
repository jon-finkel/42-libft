/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 10:49:33 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/02 20:06:14 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void				apply_field_width(t_list *list, int precision,
						enum e_flags flag)
{
	char		c;
	int			field_width;

	c = (LIST_CONTENT->zero ? '0' : ' ');
	field_width = LIST_CONTENT->field_width;
	if (flag == LEFT)
		while (field_width > precision)
		{
			pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
			--field_width;
		}
	if (flag == RIGHT)
	{
		field_width = -field_width;
		while (field_width > precision)
		{
			pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
			--field_width;
		}
	}
}

static void				copy_wide_string(const wchar_t *ws, char *s)
{
	while (*ws)
	{
		if (*ws >= 0 && *ws < 128)
			*s++ = *ws;
		if (FOUR_BYTES_UNICODE(*ws))
		{
			*s++ = FOUR_BYTES_UNICODE_HEAD(*ws);
			*s++ = THREE_BYTES_UNICODE_BODY(*ws);
		}
		if (THREE_BYTES_UNICODE(*ws))
			*s++ = THREE_BYTES_UNICODE_HEAD(*ws);
		if (THREE_OR_MORE_BYTES_UNICODE(*ws))
			*s++ = TWO_BYTES_UNICODE_BODY(*ws);
		if (TWO_BYTES_UNICODE(*ws))
			*s++ = TWO_BYTES_UNICODE_HEAD(*ws);
		if (TWO_OR_MORE_BYTES_UNICODE(*ws))
			*s++ = UNICODE_TAIL(*ws);
		++ws;
	}
}

static size_t			get_wide_length(t_list *list, const wchar_t *s)
{
	size_t				len;
	unsigned int		precision;

	len = 0;
	precision = 0;
	while (*s)
	{
		if ((int)(*s) >= 0 && (int)(*s) < 128 && ++len)
			if ((int)len <= LIST_CONTENT->precision)
				precision += 1;
		if (FOUR_BYTES_UNICODE((int)(*s)) && (len += 4))
			if ((int)len <= LIST_CONTENT->precision)
				precision += 4;
		if (THREE_BYTES_UNICODE((int)(*s)) && (len += 3))
			if ((int)len <= LIST_CONTENT->precision)
				precision += 3;
		if (TWO_BYTES_UNICODE((int)(*s)) && (len += 2))
			if ((int)len <= LIST_CONTENT->precision)
				precision += 2;
		++s;
	}
	LIST_CONTENT->precision = precision;
	return (len);
}

void					pf_output_string(t_list *list, const char *sub,
						enum e_range range)
{
	char		*string;
	int			precision;
	wchar_t		*wide_string;

	if (LIST_CONTENT->precision < 0)
		LIST_CONTENT->precision = INT_MAX;
	if (range == LONG && (wide_string = (wchar_t *)LIST_CONTENT->arg_data))
	{
		EXIT_PROTECT(string = ft_strnew(get_wide_length(list, wide_string)));
		copy_wide_string(wide_string, string);
	}
	else
		string = LIST_CONTENT->arg_data ? LIST_CONTENT->arg_data : "(null)";
	precision = MIN((int)ft_strlen(string), LIST_CONTENT->precision);
	apply_field_width(list, precision, LEFT);
	sub = ft_strsub(string, 0, precision);
	pf_fill_buffer(PF_BUFFER, 0, sub, PRINT);
	apply_field_width(list, precision, RIGHT);
	if (range == LONG && LIST_CONTENT->arg_data)
		free(string);
	free((char *)sub);
}
