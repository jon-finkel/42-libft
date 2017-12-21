/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_signed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:46:04 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/21 18:16:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static intmax_t			typecast(t_data *data, enum e_range range)
{
	if (range == LONG)
		return (va_arg(data->ap, long));
	else if (range == LONG_LONG)
		return (va_arg(data->ap, long long));
	else if (range == INTMAX_T)
		return (va_arg(data->ap, intmax_t));
	else if (range == SHORT)
		return ((short)va_arg(data->ap, int));
	else if (range == CHAR)
		return ((char)va_arg(data->ap, int));
	else if (range == SIZE_T)
		return (va_arg(data->ap, size_t));
	return (va_arg(data->ap, int));
}

static void				left_field_width(t_data *data, int *precision, int neg)
{
	int		field_width;

	field_width = data->field_width - (IS_FLAG(SPACE, data->flags) ? 1 : 0);
	if (neg)
	{
		if (IS_FLAG(ZERO, data->flags) && ++*precision)
			pf_fill_buffer(data, '-', NULL, PRINT);
		else
			--field_width;
	}
	if (!neg && IS_FLAG(PLUS, data->flags) && IS_NOT(ZERO, data->flags))
		--field_width;
	if (IS_NOT(ZERO, data->flags))
		while (field_width-- > *precision)
			pf_fill_buffer(data, ' ', NULL, PRINT);
	if (!neg && IS_FLAG(PLUS, data->flags) && ++*precision)
		pf_fill_buffer(data, '+', NULL, PRINT);
	if (IS_FLAG(ZERO, data->flags))
		while (field_width-- > *precision)
			pf_fill_buffer(data, '0', NULL, PRINT);
	if (neg && IS_NOT(ZERO, data->flags) && ++*precision)
		pf_fill_buffer(data, '-', NULL, PRINT);
}

static void				apply_flags(t_data *data, const char *s, intmax_t nb)
{
	int			k;
	int			precision;
	size_t		len;

	len = ft_strlen(s);
	if (data->precision > 0)
		UNSET_FLAG(ZERO, data->flags);
	precision = _MAX(data->precision, (int)len);
	k = precision;
	if (nb >= 0 && IS_FLAG(SPACE, data->flags))
		pf_fill_buffer(data, ' ', NULL, PRINT);
	left_field_width(data, &precision, (nb < 0 ? 1 : 0));
	if (nb >= 0 && IS_FLAG(SPACE, data->flags))
		++precision;
	while ((unsigned int)k-- > len)
		pf_fill_buffer(data, '0', NULL, PRINT);
	pf_fill_buffer(data, 0, s, PRINT);
	data->field_width = -data->field_width;
	while (data->field_width-- > precision)
		pf_fill_buffer(data, ' ', NULL, PRINT);
}

int						pf_output_signed(t_data *data, const char *base)
{
	char			tmp[MAX_LEN_INTMAX_T];
	int				k;
	intmax_t		n;
	intmax_t		nb;

	nb = typecast(data, data->range);
	k = -1;
	if (!nb && data->precision)
		tmp[++k] = '0';
	n = nb;
	while (n)
	{
		tmp[++k] = base[_ABS(n % 10)];
		n /= 10;
	}
	tmp[++k] = '\0';
	if (IS_NOT(PRECISION_CHANGED, data->flags))
		data->precision = 0;
	else if (data->precision >= 0)
		UNSET_FLAG(ZERO, data->flags);
	apply_flags(data, ft_strrev(tmp), nb);
	return (0);
}
