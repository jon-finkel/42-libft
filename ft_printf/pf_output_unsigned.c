/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:46:32 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/15 19:46:27 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static uintmax_t			typecast(t_data *data, enum e_range range)
{
	if (range == LONG)
		return (va_arg(data->ap, unsigned long));
	else if (range == LONG_LONG)
		return (va_arg(data->ap, unsigned long long));
	else if (range == INTMAX_T)
		return (va_arg(data->ap, uintmax_t));
	else if (range == SHORT)
		return ((unsigned short)va_arg(data->ap, unsigned int));
	else if (range == CHAR)
		return ((unsigned char)va_arg(data->ap, unsigned int));
	else if (range == SIZE_T)
		return (va_arg(data->ap, ssize_t));
	return (va_arg(data->ap, unsigned int));
}

static void					adjust_field_width(t_data *data, const char *base,
							uintmax_t nb, size_t len)
{
	size_t		blen;

	blen = ft_strlen(base);
	if ((base[15] == 'F' || base[15] == 'f') && nb)
	{
		if (data->field_width < 0)
			data->field_width += 2;
		else if (data->field_width >= 0)
		{
			data->field_width -= 2;
			if (len == 1 && data->field_width == -2)
				++data->field_width;
		}
	}
	else if ((blen == 8 || blen == 2) && nb)
	{
		if (data->field_width < 0)
			data->field_width += 1;
		else if (data->field_width >= 0)
			data->field_width -= 1;
	}
}

static void					left_field_width(t_data *data, const char *base,
							int *precision, uintmax_t nb)
{
	int		field_width;
	size_t	blen;

	field_width = data->field_width;
	if (IS_NOT(ZERO, data->flags))
		while (field_width-- > *precision)
			pf_fill_buffer(data, ' ', NULL, PRINT);
	blen = ft_strlen(base);
	if (IS_FLAG(ALTERNATE, data->flags))
	{
		if (base[15] == 'F' && nb)
			pf_fill_buffer(data, 0, "0X", PRINT);
		else if (base[15] == 'f' && nb)
			pf_fill_buffer(data, 0, "0x", PRINT);
		else if (blen == 8)
			pf_fill_buffer(data, '0', NULL, PRINT);
		else if (blen == 2)
			pf_fill_buffer(data, 'B', NULL, PRINT);
	}
	if (IS_FLAG(ZERO, data->flags))
		while (field_width-- > *precision)
			pf_fill_buffer(data, '0', NULL, PRINT);
}

static void					apply_flags(t_data *data, const char *s,
							const char *base, uintmax_t nb)
{
	int			k;
	int			precision;
	size_t		len;

	if (IS_NOT(PRECISION_CHANGED, data->flags))
		data->precision = 0;
	else if (data->precision >= 0)
		UNSET_FLAG(ZERO, data->flags);
	len = ft_strlen(s);
	if (data->precision)
		UNSET_FLAG(ZERO, data->flags);
	precision = MAX(data->precision, (int)len);
	if ((int)len < precision && ft_strlen(base) == 8)
		UNSET_FLAG(ALTERNATE, data->flags);
	if (IS_FLAG(ALTERNATE, data->flags))
		adjust_field_width(data, base, nb, len);
	left_field_width(data, base, &precision, nb);
	k = precision;
	while ((unsigned int)k-- > len)
		pf_fill_buffer(data, '0', NULL, PRINT);
	pf_fill_buffer(data, 0, s, PRINT);
	data->field_width = -data->field_width;
	while (data->field_width-- > precision)
		pf_fill_buffer(data, ' ', NULL, PRINT);
}

int							pf_output_unsigned(t_data *data, const char *base)
{
	char			tmp[MAX_LEN_BINARY_UINTMAX_T];
	int				k;
	size_t			base_len;
	uintmax_t		n;
	uintmax_t		nb;

	base_len = ft_strlen(base);
	nb = typecast(data, data->range);
	n = nb;
	k = -1;
	if (!nb && data->precision)
	{
		tmp[++k] = '0';
		UNSET_FLAG(ALTERNATE, data->flags);
	}
	while (n)
	{
		tmp[++k] = base[n % base_len];
		n /= base_len;
	}
	tmp[++k] = '\0';
	apply_flags(data, ft_strrev(tmp), base, nb);
	return (0);
}
