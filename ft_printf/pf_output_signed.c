/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 10:48:22 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/28 17:38:54 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t		typecast(t_list *list, enum e_range range)
{
	if (range == INT)
		return ((int)((intmax_t)LIST_CONTENT->u_arg.s_nb));
	else if (range == LONG)
		return ((long)((intmax_t)LIST_CONTENT->u_arg.s_nb));
	else if (range == LONG_LONG)
		return ((long long)((intmax_t)LIST_CONTENT->u_arg.s_nb));
	else if (range == INTMAX_T)
		return ((intmax_t)LIST_CONTENT->u_arg.s_nb);
	else if (range == SHORT)
		return ((short)((intmax_t)LIST_CONTENT->u_arg.s_nb));
	else if (range == CHAR)
		return ((char)((intmax_t)LIST_CONTENT->u_arg.s_nb));
	else if (range == SIZE_T)
		return ((ssize_t)((intmax_t)LIST_CONTENT->u_arg.s_nb));
	return (0);
}

static void			left_field_width(t_list *list, int *precision,
					enum e_range range)
{
	int			field_width;
	int			neg;

	field_width = LIST_CONTENT->field_width - LIST_CONTENT->space;
	neg = (typecast(list, range) < 0 ? 1 : 0);
	if (neg)
	{
		if (LIST_CONTENT->zero == 1 && ++*precision)
			pf_fill_buffer(PF_BUFFER, '-', NULL, PRINT);
		else
			--field_width;
	}
	if (!neg && LIST_CONTENT->plus == 1 && LIST_CONTENT->zero == 0)
		--field_width;
	if (!LIST_CONTENT->zero)
		while (field_width-- > *precision)
			pf_fill_buffer(PF_BUFFER, ' ', NULL, PRINT);
	if (!neg && LIST_CONTENT->plus == 1 && ++*precision)
		pf_fill_buffer(PF_BUFFER, '+', NULL, PRINT);
	if (LIST_CONTENT->zero)
		while (field_width-- > *precision)
			pf_fill_buffer(PF_BUFFER, '0', NULL, PRINT);
	if (neg && LIST_CONTENT->zero == 0 && ++*precision)
		pf_fill_buffer(PF_BUFFER, '-', NULL, PRINT);
}

static void			apply_flags(t_list *list, const char *s, enum e_range range)
{
	int			k;
	int			precision;
	size_t		len;

	len = ft_strlen(s);
	if (LIST_CONTENT->precision > 0)
		LIST_CONTENT->zero = 0;
	precision = MAX(LIST_CONTENT->precision, (int)len);
	k = precision;
	if (typecast(list, range) >= 0 && LIST_CONTENT->space == 1)
		pf_fill_buffer(PF_BUFFER, ' ', NULL, PRINT);
	left_field_width(list, &precision, range);
	if (typecast(list, range) >= 0 && LIST_CONTENT->space == 1)
		++precision;
	while ((unsigned int)k-- > len)
		pf_fill_buffer(PF_BUFFER, '0', NULL, PRINT);
	pf_fill_buffer(PF_BUFFER, 0, s, PRINT);
	LIST_CONTENT->field_width = -LIST_CONTENT->field_width;
	while (LIST_CONTENT->field_width-- > precision)
		pf_fill_buffer(PF_BUFFER, ' ', NULL, PRINT);
}

void				pf_output_signed(t_list *list, const char *base,
					enum e_range range)
{
	char		tmp[MAX_LEN_INTMAX_T];
	int			k;
	intmax_t	nb;

	k = -1;
	nb = typecast(list, range);
	if (nb == 0 && LIST_CONTENT->zero_precision == NATIVE)
		tmp[++k] = '0';
	while (nb)
	{
		tmp[++k] = base[ABS(nb % 10)];
		nb /= 10;
	}
	tmp[++k] = '\0';
	apply_flags(list, ft_strrev(tmp), range);
}
