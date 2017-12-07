/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_initialize_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 19:19:57 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/07 21:43:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static const struct s_type		g_type[] =
{
	{'*', SIGNED_ARG},
	{'d', SIGNED_ARG},
	{'s', POINTER},
	{'u', UNSIGNED_ARG},
	{'p', POINTER},
	{'c', UNSIGNED_ARG},
	{'f', DOUBLE_ARG},
	{'F', DOUBLE_ARG},
	{'i', SIGNED_ARG},
	{'x', UNSIGNED_ARG},
	{'X', UNSIGNED_ARG},
	{'b', UNSIGNED_ARG},
	{'o', UNSIGNED_ARG},
	{'r', POINTER},
	{'D', SIGNED_ARG},
	{'U', UNSIGNED_ARG},
	{'O', UNSIGNED_ARG},
	{'S', POINTER},
	{'C', UNSIGNED_ARG}
};

#include <stdio.h>
static t_args				*init_struct(va_list ap, const char format,
							enum e_type data_type)
{
	t_args		*args;

	EXIT_PROTECT(args = (t_args *)malloc(sizeof(t_args)));
	args->arg_data = (data_type == POINTER ? va_arg(ap, void *) : NULL);
	if (data_type == SIGNED_ARG)
		args->u_arg.s_nb = va_arg(ap, intmax_t);
	else if (data_type == UNSIGNED_ARG)
		args->u_arg.u_nb = va_arg(ap, uintmax_t);
	else if (data_type == DOUBLE_ARG)
		args->u_arg.d_nb = va_arg(ap, double);
	else
		args->u_arg.u_nb = (uintmax_t)format;
	args->alternate_form = 0;
	args->field_width = 0;
	args->negative = 1;
	args->plus = 0;
	args->precision = (data_type == POINTER ? INT_MAX : 0);
	args->zero_precision = NATIVE;
	args->space = 0;
	args->zero = 0;
	return (args);
}

static void					arg_to_list(t_list **alist, t_buffer *buffer,
							t_args **aargs)
{
	t_args		*args;
	t_list		*list;

	args = *aargs;
	args->buffer = buffer;
	if (!*alist)
	{
		EXIT_PROTECT(*alist = ft_lstnew(args, sizeof(t_args)));
		list = *alist;
	}
	else
	{
		list = *alist;
		while (list->next)
			list = list->next;
		EXIT_PROTECT(list->next = ft_lstnew(args, sizeof(t_args)));
	}
	free(args);
	*aargs = NULL;
}

static enum e_type			get_data_type(t_buffer *buffer, const char **afmt,
							size_t len)
{
	int			p;

	++*afmt;
	while (((**afmt > 47 && **afmt < 58) || **afmt == '.' || **afmt == '#'
		|| **afmt == ' ' || **afmt == '-' || **afmt == '+' || **afmt == 'h'
			|| **afmt == 'l' || **afmt == 'j' || **afmt == 'z') && ++len)
		++*afmt;
	if (!**afmt)
	{
		buffer->invalid = len;
		return (END);
	}
	p = -1;
	while (++p < LAST_TYPE)
		if (g_type[p].letter == **afmt)
		{
			if (**afmt == '*')
				--*afmt;
			return (g_type[p].data_type);
		}
	return (NOT_FLAG);
}

void						pf_initialize_list(t_list **alist, t_buffer *buffer,
							const char *format, va_list ap)
{
	enum e_type		data_type;
	t_args			*args;

	while (*format)
	{
		if (*format == '%' || *format == '*')
		{
			while (*format == '%' && *(format + 1) == '%')
				if (!(format = ft_strchr(format + 2, '%')) || !*(format + 1))
					return ;
			if ((data_type = get_data_type(buffer, &format, 1)) == END)
				return ;
			args = init_struct(ap, *format, data_type);
			arg_to_list(alist, buffer, &args);
		}
		++format;
	}
}
