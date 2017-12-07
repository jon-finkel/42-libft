/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:41:26 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/07 23:50:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void					apply_field_width(t_list *list, size_t len,
							enum e_flags flag)
{
	char		c;
	int			field_width;

	c = (LIST_CONTENT->zero ? '0' : ' ');
	field_width = LIST_CONTENT->field_width;
	if (LIST_CONTENT->zero && LIST_CONTENT->u_arg.d_nb < 0)
		pf_fill_buffer(PF_BUFFER, '-', NULL, PRINT);
	if (flag == LEFT)
		while (field_width > (int)len)
		{
			pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
			--field_width;
		}
	if (!LIST_CONTENT->zero && LIST_CONTENT->u_arg.d_nb < 0)
		pf_fill_buffer(PF_BUFFER, '-', NULL, PRINT);
	if (flag == RIGHT)
	{
		field_width = -field_width;
		while (field_width > (int)len)
		{
			pf_fill_buffer(PF_BUFFER, c, NULL, PRINT);
			--field_width;
		}
	}
	LIST_CONTENT->u_arg.d_nb = 1.00;
}

static int					map_precision(t_list *list, const char *base,
							char *buff, double nb)
{
	double			mantissa;
	int				k;
	int				zeroes;
	intmax_t		integer;

	mantissa = nb - (intmax_t)nb;
	if (!LIST_CONTENT->precision && LIST_CONTENT->zero_precision == NATIVE)
		LIST_CONTENT->precision = 6;
	zeroes = LIST_CONTENT->precision;
	while (LIST_CONTENT->precision--)
		mantissa *= 10;
	integer = (intmax_t)mantissa;
	if (integer > 9999 && integer % 10 != 0)
		++integer;
	zeroes -= ft_intlen(integer) - (!integer ? 1 : 0);
	k = -1;
	while (integer)
	{
		buff[++k] = base[integer % 10];
		integer /= 10;
	}
	while (zeroes-- > 0)
		buff[++k] = '0';
	return (k);
}

void						pf_output_double(t_list *list, const char *base,
							enum e_range range)
{
	char			buff[256];
	double			nb;
	int				k;
	intmax_t		integer;
	size_t			len;

	(void)range;
	ft_bzero(buff, 256);
	nb = LIST_CONTENT->u_arg.d_nb;
	k = map_precision(list, base, buff, (nb < 0 ? -nb : nb));
	if (k > -1)
		buff[++k] = '.';
	integer = (intmax_t)(nb < 0 ? -nb : nb);
	if (!integer)
		buff[++k] = '0';
	while (integer)
	{
		buff[++k] = base[integer % 10];
		integer /= 10;
	}
	len = ft_strlen(buff) + (nb < 0 ? 1 : 0);
	apply_field_width(list, len, LEFT);
	pf_fill_buffer(PF_BUFFER, 0, ft_strrev(buff), PRINT);
	apply_field_width(list, len, RIGHT);
}
