/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:10:24 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/24 11:25:23 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static const char			*get_precision(t_data *data, const char *format)
{
	int		nb;

	while (*format == '.')
		++format;
	nb = ft_atoi(format);
	if (nb > 0)
	{
		data->precision = nb;
		SET_FLAG(E_PRECISION_CHANGED, data->flags);
		format += ft_intlen(nb);
	}
	else if (*format == '*')
	{
		data->precision = va_arg(data->ap, int);
		SET_FLAG(E_PRECISION_CHANGED, data->flags);
		++format;
	}
	else if (*format < '0' || *format > '9')
	{
		data->precision = 0;
		SET_FLAG(E_PRECISION_CHANGED, data->flags);
	}
	return (format);
}

static const char			*get_field_width(t_data *data, const char *format)
{
	int		nb;

	nb = ft_atoi(format);
	if (nb && *(format + ft_intlen(nb)) != '*')
	{
		while (*format == '*' && ++format)
			nb = ft_atoi(format);
		data->field_width = (IS_FLAG(E_NEGATIVE, data->flags) ? -nb : nb);
		format += ft_intlen(nb);
	}
	else if (*format == '*' || (nb && *(format + ft_intlen(nb)) == '*'))
	{
		if (nb)
			format += ft_intlen(nb);
		data->field_width = va_arg(data->ap, int);
		++format;
	}
	else
		data->field_width = 0;
	return (format);
}

static const char			*get_modifiers(t_data *data, const char *format,
							t_flag flag)
{
	while (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
		|| *format == '0')
	{
		if (*format == '#')
			SET_FLAG(E_ALTERNATE, data->flags);
		else if (*format == ' ')
			SET_FLAG(E_SPACE, data->flags);
		else if (*format == '+')
			SET_FLAG(E_PLUS, data->flags);
		else if (*format == '-')
			SET_FLAG(E_NEGATIVE, data->flags);
		else if (flag == E_FIRST && *format == '0')
			SET_FLAG(E_ZERO, data->flags);
		++format;
	}
	return (format);
}

const char					*pf_get_flags(t_data *data, const char *format,
							t_flag flag)
{
	while (*format == '{')
		format = pf_ansi_color(data, format, E_NARROW);
	format = get_modifiers(data, format, flag);
	if (flag == E_FIRST)
		format = get_field_width(data, format);
	if (ft_atoi(format))
		format = get_field_width(data, format);
	if (*format == '.' && ++format)
	{
		while (*format == '0' && ++format)
			data->precision = 0;
		format = get_precision(data, format);
		if (flag == E_SECOND)
			format = get_modifiers(data, format, flag);
	}
	if (IS_FLAG(E_PLUS, data->flags))
		UNSET_FLAG(E_SPACE, data->flags);
	return (format);
}
