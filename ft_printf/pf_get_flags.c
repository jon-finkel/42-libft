/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 06:49:28 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 11:56:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static t_list			*wildcard_copy(t_list *list, enum e_flags flag)
{
	NEXT_CONTENT->alternate_form = LIST_CONTENT->alternate_form;
	NEXT_CONTENT->plus = LIST_CONTENT->plus;
	NEXT_CONTENT->space = LIST_CONTENT->space;
	NEXT_CONTENT->zero = LIST_CONTENT->zero;
	if (flag == FIELD_WIDTH)
		NEXT_CONTENT->field_width = (int)LIST_CONTENT->u_arg.s_nb;
	else
		NEXT_CONTENT->field_width = LIST_CONTENT->field_width;
	if (flag == PRECISION)
	{
		NEXT_CONTENT->precision = (int)LIST_CONTENT->u_arg.s_nb;
		if (NEXT_CONTENT->precision == 0)
			NEXT_CONTENT->zero_precision = MODIFIED;
	}
	return (list->next);
}

static t_list			*get_precision(t_list *list, const char **format)
{
	int		nb;

	while (**format == '.')
		++*format;
	nb = ft_atoi(*format);
	if (nb > 0)
	{
		LIST_CONTENT->precision = nb;
		*format += ft_intlen(nb);
	}
	else if (**format == '*' && ++*format)
		list = wildcard_copy(list, PRECISION);
	else if (**format < '0' || **format > '9')
	{
		LIST_CONTENT->precision = 0;
		LIST_CONTENT->zero_precision = MODIFIED;
	}
	return (list);
}

static t_list			*get_field_width(t_list *list, const char **format)
{
	int		nb;

	nb = ft_atoi(*format);
	if (nb && *(*format + ft_intlen(nb)) != '*')
	{
		while (**format == '*' && ++*format)
			nb = ft_atoi(*format);
		LIST_CONTENT->field_width = nb * LIST_CONTENT->negative;
		*format += ft_intlen(nb);
	}
	else if (**format == '*' || (nb && *(*format + ft_intlen(nb)) == '*'))
	{
		if (nb)
			*format += ft_intlen(nb);
		list = wildcard_copy(list, FIELD_WIDTH);
		++*format;
	}
	else
		LIST_CONTENT->field_width = 0;
	return (list);
}

static void				get_modifiers(t_list *list, const char **format,
						enum e_flags flag)
{
	while (**format == '#' || **format == ' ' || **format == '+'
		|| **format == '0' || **format == '-')
	{
		if (**format == '#')
			LIST_CONTENT->alternate_form = 1;
		else if (**format == ' ')
			LIST_CONTENT->space = 1;
		else if (**format == '+')
			LIST_CONTENT->plus = 1;
		else if (flag == FIRST && **format == '0')
			LIST_CONTENT->zero = 1;
		else if (**format == '-')
			LIST_CONTENT->negative = -1;
		++*format;
	}
}

t_list					*pf_get_flags(t_list *list, const char **format,
						enum e_flags flag)
{
	get_modifiers(list, format, flag);
	if (flag == FIRST)
		list = get_field_width(list, format);
	if (ft_atoi(*format))
		list = get_field_width(list, format);
	if (**format == '.' && ++*format)
	{
		while (**format == '0' && ++*format)
			LIST_CONTENT->precision = 0;
		list = get_precision(list, format);
		if (flag == SECOND)
			get_modifiers(list, format, flag);
	}
	if ((LIST_CONTENT->precision > 0 && LIST_CONTENT->precision != INT_MAX)
			|| LIST_CONTENT->field_width < 0)
		LIST_CONTENT->zero = 0;
	if (LIST_CONTENT->plus == 1)
		LIST_CONTENT->space = 0;
	return (list);
}
