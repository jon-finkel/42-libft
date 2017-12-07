/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 20:41:26 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/07 22:26:54 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	zeroes -= ft_intlen(integer);
	k = -1;
	while (integer)
	{
		buff[++k] = base[integer % 10];
		integer /= 10;
	}
	while (zeroes-- > 0)
		buff[++k] = '0';
	if (k > -1)
		buff[++k] = '.';
	return (k);
}

void						pf_output_double(t_list *list, const char *base,
							enum e_range range)
{
	char			buff[256];
	double			nb;
	int				k;
	intmax_t		integer;

	(void)range;
	ft_bzero(buff, 256);
	nb = LIST_CONTENT->u_arg.d_nb;
	k = map_precision(list, base, buff, (nb < 0 ? -nb : nb));
	integer = (intmax_t)(nb < 0 ? -nb : nb);
	if (!integer && buff[k] == '.')
		buff[++k] = '0';
	while (integer)
	{
		buff[++k] = base[integer % 10];
		integer /= 10;
	}
	pf_fill_buffer(PF_BUFFER, 0, ft_strrev(buff), PRINT);
}
