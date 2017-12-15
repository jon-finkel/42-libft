/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:43:51 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/15 19:45:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static int			map_precision(t_data *data, const char *base, char *buff,
					double nb)
{
	double			mantissa;
	int				k;
	int				zeroes;
	uintmax_t		integer;

	mantissa = nb - (uintmax_t)nb;
	if (data->precision == INT_MAX)
		data->precision = 6;
	zeroes = data->precision;
	while (data->precision--)
		mantissa *= 10;
	integer = (uintmax_t)mantissa;
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

static void			apply_left_field_width(t_data *data, size_t len, double nb)
{
	char		filler;
	int			field_width;

	filler = (IS_FLAG(ZERO, data->flags) ? '0' : ' ');
	field_width = data->field_width;
	if (IS_FLAG(ZERO, data->flags) && nb < 0)
		pf_fill_buffer(data, '-', NULL, PRINT);
	while (field_width-- > (int)len)
		pf_fill_buffer(data, filler, NULL, PRINT);
	if (IS_NOT(ZERO, data->flags) && nb < 0)
		pf_fill_buffer(data, '-', NULL, PRINT);
}

static void			apply_right_field_width(t_data *data, size_t len)
{
	int			field_width;

	field_width = -data->field_width;
	while (field_width-- > (int)len)
		pf_fill_buffer(data, ' ', NULL, PRINT);
}

int					pf_output_double(t_data *data, const char *base)
{
	char			buff[256];
	double			nb;
	int				k;
	size_t			len;
	uintmax_t		integer;

	ft_bzero(buff, 256);
	nb = va_arg(data->ap, double);
	k = map_precision(data, base, buff, (nb < 0 ? -nb : nb));
	if (k > -1)
		buff[++k] = '.';
	integer = (uintmax_t)(nb < 0 ? -nb : nb);
	if (!integer)
		buff[++k] = '0';
	while (integer)
	{
		buff[++k] = base[integer % 10];
		integer /= 10;
	}
	len = ft_strlen(buff) + (nb < 0 ? 1 : 0);
	apply_left_field_width(data, len, nb);
	pf_fill_buffer(data, 0, ft_strrev(buff), PRINT);
	apply_right_field_width(data, len);
	return (0);
}
