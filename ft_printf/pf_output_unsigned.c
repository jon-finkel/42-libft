/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 10:49:46 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 12:00:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static uintmax_t			typecast(t_list *list, enum e_range range)
{
	if (range == INT)
		return ((unsigned int)((uintmax_t)LIST_CONTENT->u_arg.u_nb));
	else if (range == LONG)
		return ((unsigned long)((uintmax_t)LIST_CONTENT->u_arg.u_nb));
	else if (range == LONG_LONG)
		return ((unsigned long long)((uintmax_t)LIST_CONTENT->u_arg.u_nb));
	else if (range == INTMAX_T)
		return ((uintmax_t)LIST_CONTENT->u_arg.u_nb);
	else if (range == SHORT)
		return ((unsigned short)((uintmax_t)LIST_CONTENT->u_arg.u_nb));
	else if (range == CHAR)
		return ((unsigned char)((uintmax_t)LIST_CONTENT->u_arg.u_nb));
	else if (range == SIZE_T)
		return ((size_t)((uintmax_t)LIST_CONTENT->u_arg.u_nb));
	return (0);
}

static void					field_width(t_list *list, const char *base,
							enum e_flags flag, int *precision)
{
	int		field_width;

	field_width = LIST_CONTENT->field_width;
	if (flag == RIGHT)
		field_width = -field_width;
	if (LIST_CONTENT->zero == 0)
		while (flag == LEFT && field_width-- > *precision)
			pf_fill_buffer(PF_BUFFER, ' ', NULL, PRINT);
	if (LIST_CONTENT->alternate_form == 1)
	{
		if (base[15] == 'F' && LIST_CONTENT->u_arg.u_nb)
			pf_fill_buffer(PF_BUFFER, 0, "0X", PRINT);
		else if (base[15] == 'f' && LIST_CONTENT->u_arg.u_nb)
			pf_fill_buffer(PF_BUFFER, 0, "0x", PRINT);
		else if (ft_strlen(base) == 8)
			pf_fill_buffer(PF_BUFFER, '0', NULL, PRINT);
	}
	if (LIST_CONTENT->zero == 1)
		while (flag == LEFT && field_width-- > *precision)
			pf_fill_buffer(PF_BUFFER, '0', NULL, PRINT);
	while (flag == RIGHT && field_width-- > *precision)
		pf_fill_buffer(PF_BUFFER, ' ', NULL, PRINT);
}

static void					adjust_field_width(t_list *list, const char *base,
							size_t len)
{
	if ((base[15] == 'F' || base[15] == 'f') && LIST_CONTENT->u_arg.u_nb)
	{
		if (LIST_CONTENT->field_width < 0)
			LIST_CONTENT->field_width += 2;
		else if (LIST_CONTENT->field_width >= 0)
		{
			LIST_CONTENT->field_width -= 2;
			if (len == 1 && LIST_CONTENT->field_width == -2)
				++LIST_CONTENT->field_width;
		}
	}
	else if (ft_strlen(base) == 8 && LIST_CONTENT->u_arg.u_nb)
	{
		if (LIST_CONTENT->field_width < 0)
			LIST_CONTENT->field_width += 1;
		else if (LIST_CONTENT->field_width >= 0)
			LIST_CONTENT->field_width -= 1;
	}
}

static void					apply_flags(t_list *list, const char *s,
							const char *base)
{
	int			k;
	int			precision;
	size_t		len;

	len = ft_strlen(s);
	if (LIST_CONTENT->precision)
		LIST_CONTENT->zero = 0;
	precision = MAX(LIST_CONTENT->precision, (int)len);
	if ((int)len < precision && ft_strlen(base) == 8)
		LIST_CONTENT->alternate_form = 0;
	if (LIST_CONTENT->alternate_form == 1)
		adjust_field_width(list, base, len);
	field_width(list, base, LEFT, &precision);
	LIST_CONTENT->alternate_form = 0;
	k = precision;
	while ((unsigned int)k-- > len)
		pf_fill_buffer(PF_BUFFER, '0', NULL, PRINT);
	pf_fill_buffer(PF_BUFFER, 0, s, PRINT);
	field_width(list, base, RIGHT, &precision);
}

void						pf_output_unsigned(t_list *list, const char *base,
							enum e_range range)
{
	char			tmp[MAX_LEN_BINARY_UINTMAX_T];
	int				k;
	size_t			base_len;
	uintmax_t		nb;

	k = -1;
	base_len = ft_strlen(base);
	nb = typecast(list, range);
	if (nb == 0 && LIST_CONTENT->zero_precision == NATIVE)
	{
		tmp[++k] = '0';
		LIST_CONTENT->alternate_form = 0;
	}
	while (nb > 0)
	{
		tmp[++k] = base[nb % base_len];
		nb /= base_len;
	}
	tmp[++k] = '\0';
	apply_flags(list, ft_strrev(tmp), base);
}
