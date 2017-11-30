/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:07 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/30 21:25:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static const struct s_conv	g_conv[] =
{
	{'d', &pf_output_signed, "0123456789", VOID},
	{'s', &pf_output_string, NULL, VOID},
	{'u', &pf_output_unsigned, "0123456789", VOID},
	{'p', &pf_output_pointer, "0123456789abcdef", VOID},
	{'c', &pf_output_char, NULL, VOID},
	{'i', &pf_output_signed, "0123456789", VOID},
	{'x', &pf_output_unsigned, "0123456789abcdef", VOID},
	{'X', &pf_output_unsigned, "0123456789ABCDEF", VOID},
	{'b', &pf_output_unsigned, "01", VOID},
	{'o', &pf_output_unsigned, "01234567", VOID},
	{'r', &pf_output_noprint, "0123456789abcdef", VOID},
	{'D', &pf_output_signed, "0123456789", LONG},
	{'U', &pf_output_unsigned, "0123456789", LONG},
	{'O', &pf_output_unsigned, "01234567", LONG},
	{'S', &pf_output_string, NULL, LONG},
	{'C', &pf_output_char, NULL, LONG}
};

static void					adjust_range(const char **format,
							enum e_range *range)
{
	while (**format == 'j' || **format == 'z' || **format == 'l'
		|| **format == 'h')
	{
		if (**format == 'j' && *range < INTMAX_T)
			*range = INTMAX_T;
		else if (**format == 'z' && *range < SIZE_T)
			*range = SIZE_T;
		else if (**format == 'l' && *(*format + 1) == 'l' && *range < LONG_LONG)
		{
			++*format;
			*range = LONG_LONG;
		}
		else if (**format == 'l' && *range < LONG)
			*range = LONG;
		else if (**format == 'h' && *(*format + 1) == 'h' && *range < CHAR)
		{
			++*format;
			*range = CHAR;
		}
		else if (**format == 'h' && *range < SHORT)
			*range = SHORT;
		++*format;
	}
}

static void					print_conversion(t_list *list, const char **format,
							enum e_range range)
{
	int				k;

	adjust_range(format, &range);
	pf_get_flags(list, format, SECOND);
	k = -1;
	while (++k < LAST_CONVERSION)
		if ((unsigned char)**format == (unsigned char)g_conv[k].letter)
		{
			if (g_conv[k].range != VOID && range != LONG)
				range = g_conv[k].range;
			g_conv[k].f(list, g_conv[k].base, range);
			break ;
		}
	if (k == LAST_CONVERSION)
		pf_output_char(list, NULL, CHAR);
	++*format;
}

static void					buff_format(const char *format, t_list *list,
							t_buffer *buffer)
{
	int				k;
	size_t			valid;

	valid = ft_strlen(format) - buffer->invalid;
	k = -1;
	while (*format && (unsigned int)++k < valid)
	{
		if (*format && *format != '%')
			pf_fill_buffer(buffer, *format++, NULL, PRINT);
		else if (*format == '%' && ++format)
		{
			if (*format == '%')
				pf_fill_buffer(buffer, *format++, NULL, PRINT);
			else if (*format)
			{
				list = pf_get_flags(list, &format, FIRST);
				print_conversion(list, &format, INT);
				list = list->next;
			}
		}
	}
}

static t_buffer				*initialize_buffer(char *str, size_t size,
							size_t *len)
{
	t_buffer		*buffer;

	if (!(buffer = (t_buffer *)malloc(sizeof(t_buffer))))
		exit(EXIT_FAILURE);
	buffer->pf_buffer = str;
	buffer->pf_len = len;
	buffer->spf_size = size - 1;
	buffer->pf_type = SPRINTF;
	buffer->invalid = 0;
	return (buffer);
}

int							ft_vsnprintf(char *str, size_t size,
							const char *format, va_list ap)
{
	size_t			len;
	t_buffer		*buffer;
	t_list			*list;
	t_list			*tmp;

	if (!size)
		return (0);
	len = 0;
	list = NULL;
	buffer = initialize_buffer(str, size, &len);
	pf_initialize_list(&list, buffer, format, ap);
	buff_format(format, list, buffer);
	*(str + size) = '\0';
	while (list)
	{
		tmp = list->next;
		free(LIST_CONTENT);
		free(list);
		list = tmp;
	}
	free(buffer);
	return ((int)len);
}
