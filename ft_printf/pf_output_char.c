/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 21:03:53 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/28 17:37:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			apply_field_width(t_list *list, enum e_flags flag)
{
	char		c;
	int			field_width;

	c = (LIST_CONTENT->zero ? '0' : ' ');
	field_width = LIST_CONTENT->field_width;
	if (flag == LEFT)
		while (field_width > 1)
		{
			pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
			--field_width;
		}
	if (flag == RIGHT)
	{
		field_width = -field_width;
		while (field_width > 1)
		{
			pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
			--field_width;
		}
	}
}

static void			output_wide_char(t_list *list, int c)
{
	if (c >= 0 && c < 128)
		pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
	if (FOUR_BYTES_UNICODE(c))
	{
		pf_fill_buffer(PF_BUFFER, FOUR_BYTES_UNICODE_HEAD(c), NULL, PRINT);
		pf_fill_buffer(PF_BUFFER, THREE_BYTES_UNICODE_BODY(c), NULL, PRINT);
	}
	if (THREE_BYTES_UNICODE(c))
		pf_fill_buffer(PF_BUFFER, THREE_BYTES_UNICODE_HEAD(c), NULL, PRINT);
	if (THREE_OR_MORE_BYTES_UNICODE(c))
		pf_fill_buffer(PF_BUFFER, TWO_BYTES_UNICODE_BODY(c), NULL, PRINT);
	if (TWO_BYTES_UNICODE(c))
		pf_fill_buffer(PF_BUFFER, TWO_BYTES_UNICODE_HEAD(c), NULL, PRINT);
	if (TWO_OR_MORE_BYTES_UNICODE(c))
		pf_fill_buffer(PF_BUFFER, UNICODE_TAIL(c), NULL, PRINT);
}

void				pf_output_char(t_list *list, const char *base,
					enum e_range range)
{
	unsigned char		c;

	(void)base;
	apply_field_width(list, LEFT);
	if (range == LONG)
		output_wide_char(list, (int)LIST_CONTENT->u_arg.u_nb);
	else
	{
		c = (unsigned char)LIST_CONTENT->u_arg.u_nb;
		pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
	}
	apply_field_width(list, RIGHT);
}
