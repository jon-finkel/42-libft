/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_noprint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:03:45 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/28 17:38:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			apply_field_width(t_list *list, int precision,
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
	else if (flag == RIGHT)
	{
		field_width = -field_width;
		while (field_width > precision)
		{
			pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
			--field_width;
		}
	}
}

static void			copy_string(char *dst, char *src, int precision,
					const char *base)
{
	while (*src && precision)
	{
		if (!ft_isprint(*src))
		{
			*dst++ = '\\';
			*dst++ = '0';
			*dst++ = 'x';
			*dst++ = base[(*src / 16) % 16];
			*dst++ = base[*src % 16];
			precision -= 4;
		}
		else
			*dst++ = *src;
		++src;
		--precision;
	}
}

void				pf_output_noprint(t_list *list, const char *base,
					enum e_range range)
{
	char		*string;
	int			precision;
	size_t		len;

	(void)range;
	if (!(char *)LIST_CONTENT->arg_data)
		return (pf_output_string(list, NULL, VOID));
	string = (char *)LIST_CONTENT->arg_data;
	precision = 0;
	len = 0;
	while (*string && ++string && ++len)
	{
		if (ft_isprint(*(string - 1)) && (int)len <= LIST_CONTENT->precision)
			++precision;
		if (!ft_isprint(*(string - 1)) && (len += 4))
			if ((int)len <= LIST_CONTENT->precision)
				precision += 5;
	}
	if (!(string = ft_strnew(precision)))
		exit(EXIT_FAILURE);
	copy_string(string, (char *)LIST_CONTENT->arg_data, precision, base);
	apply_field_width(list, precision, LEFT);
	pf_fill_buffer(PF_BUFFER, 0, string, PRINT);
	apply_field_width(list, precision, RIGHT);
	free(string);
}
