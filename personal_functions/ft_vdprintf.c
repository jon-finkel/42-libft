/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:02:38 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/28 17:48:50 by nfinkel          ###   ########.fr       */
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
		while (*format == '{')
			format = pf_ansi_color(buffer, format, &k);
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
	if (buffer->flag == COLOR)
		pf_fill_buffer(buffer, 0, "\033[0m", NON_PRINT);
}

static t_buffer				*initialize_buffer(size_t *len)
{
	t_buffer		*buffer;

	if (!(buffer = (t_buffer *)malloc(sizeof(t_buffer))))
		exit(EXIT_FAILURE);
	if (!(buffer->pf_buffer = ft_strnew(PRINTF_BUFFSIZE)))
		exit(EXIT_FAILURE);
	buffer->pf_len = len;
	buffer->flag = NO_COLOR;
	buffer->invalid = 0;
	buffer->non_printable = 0;
	buffer->size_factor = 1;
	return (buffer);
}

int							ft_vdprintf(int fd, const char *format, va_list ap)
{
	size_t			len;
	t_buffer		*buffer;
	t_list			*list;
	t_list			*tmp;

	len = 0;
	list = NULL;
	buffer = initialize_buffer(&len);
	pf_initialize_list(&list, buffer, format, ap);
	buff_format(format, list, buffer);
	write(fd, buffer->pf_buffer, *buffer->pf_len);
	len -= buffer->non_printable;
	while (list)
	{
		tmp = list->next;
		free(LIST_CONTENT);
		free(list);
		list = tmp;
	}
	free(buffer->pf_buffer);
	free(buffer);
	return ((int)len);
}
