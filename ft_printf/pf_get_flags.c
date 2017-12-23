/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 22:10:24 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/23 19:56:40 by nfinkel          ###   ########.fr       */
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
		SET_FLAG(PRECISION_CHANGED, data->flags);
		format += ft_intlen(nb);
	}
	else if (*format == '*')
	{
		data->precision = va_arg(data->ap, int);
		SET_FLAG(PRECISION_CHANGED, data->flags);
		++format;
	}
	else if (*format < '0' || *format > '9')
	{
		data->precision = 0;
		SET_FLAG(PRECISION_CHANGED, data->flags);
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
		data->field_width = (IS_FLAG(NEGATIVE, data->flags) ? -nb : nb);
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
							enum e_flags flag)
{
	while (*format == '#' || *format == ' ' || *format == '+' || *format == '-'
		|| *format == '0')
	{
		if (*format == '#')
			SET_FLAG(ALTERNATE, data->flags);
		else if (*format == ' ')
			SET_FLAG(SPACE, data->flags);
		else if (*format == '+')
			SET_FLAG(PLUS, data->flags);
		else if (*format == '-')
			SET_FLAG(NEGATIVE, data->flags);
		else if (flag == FIRST && *format == '0')
			SET_FLAG(ZERO, data->flags);
		++format;
	}
	return (format);
}

const char					*pf_get_flags(t_data *data, const char *format,
							enum e_flags flag)
{
	while (*format == '{')
		format = pf_ansi_color(data, format, NARROW);
	format = get_modifiers(data, format, flag);
	if (flag == FIRST)
		format = get_field_width(data, format);
	if (ft_atoi(format))
		format = get_field_width(data, format);
	if (*format == '.' && ++format)
	{
		while (*format == '0' && ++format)
			data->precision = 0;
		format = get_precision(data, format);
		if (flag == SECOND)
			format = get_modifiers(data, format, flag);
	}
	if (IS_FLAG(PLUS, data->flags))
		UNSET_FLAG(SPACE, data->flags);
	return (format);
}
