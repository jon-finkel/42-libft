/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:42:24 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/24 09:41:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include "../includes/libft.h"

# define ANSI_STRING_BUFFSIZE 18
# define ASPRINTF_BUFFSIZE 128
# define PRINTF_BUFFSIZE 4096

# define LAST_COLOR_FLAG 22
# define LAST_CONVERSION_FLAG 18
# define MAX_LEN_INTMAX_T 20
# define MAX_LEN_BINARY_UINTMAX_T 64
# define MAX_LEN_POINTER 18

# define FOUR_BYTES_UNICODE(x) (x >= 0x10000 && x <= 0x10FFFF)
# define THREE_BYTES_UNICODE(x) (x >= 0x800 && x < 0x10000)
# define TWO_BYTES_UNICODE(x) (x >= 0x80 && x < 0x800)
# define THREE_OR_MORE_BYTES_UNICODE(x) (x >= 0x800 && x <= 0x10FFFF)
# define TWO_OR_MORE_BYTES_UNICODE(x) (x >= 0x80 && x <= 0x10FFFF)
# define FOUR_BYTES_UNICODE_HEAD(x) (x >> 18 | 0xF0)
# define THREE_BYTES_UNICODE_HEAD(x) (x >> 12 | 0xE0)
# define THREE_BYTES_UNICODE_BODY(x) ((x >> 12 & 0x3F) | 0x80)
# define TWO_BYTES_UNICODE_HEAD(x) (x >> 6 | 0xC0)
# define TWO_BYTES_UNICODE_BODY(x) ((x >> 6 & 0x3F) | 0x80)
# define UNICODE_TAIL(x) ((x & 0x3F) | 0x80)

enum				e_flags
{
	E_ALTERNATE = 1,
	E_NEGATIVE = 2,
	E_PLUS = 4,
	E_SPACE = 8,
	E_ZERO = 16,
	E_PRECISION_CHANGED = 32,
	E_ANSI_COLOR = 64,
	E_FIRST,
	E_SECOND,
	E_PRINT,
	E_NON_PRINT,
	E_NARROW,
	E_WIDE,
	E_PRINTF,
	E_SPRINTF,
	E_ASPRINTF
};

enum				e_range
{
	E_VOID = 0,
	E_INT = 1,
	E_CHAR = 2,
	E_SHORT = 3,
	E_SIZE_T = 4,
	E_LONG = 5,
	E_LONG_LONG = 6,
	E_INTMAX_T = 7
};

typedef struct		s_data
{
	enum e_flags	pf_type;
	char			*pf_buffer;
	size_t			pf_len;
	size_t			pf_max_len;
	int				fd;
	size_t			index;
	size_t			non_printable;
	enum e_range	range;
	char			ansi_colors[ANSI_STRING_BUFFSIZE];
	t_bool			color_multiple_flags;
	char			error;
	char			c;
	bitmap8_t		flags;
	int				field_width;
	int				precision;
	va_list			ap;
}					t_data;

struct				s_color
{
	char			letter;
	char			code;
};

struct				s_conv
{
	char			letter;
	int				(*f)(t_data *, const char *);
	const char		*base;
	enum e_range	range;
};

void				pf_fill_buffer(t_data *data, const char filler,
					const char *s_filler, enum e_flags flag);
const char			*pf_get_flags(t_data *data, const char *format,
					enum e_flags flag);
const char			*pf_ansi_color(t_data *data, const char *format,
					enum e_flags flag);
void				pf_buff_format(t_data *data, const char *format);
int					pf_output_char(t_data *data, const char *base);
int					pf_output_double(t_data *data, const char *base);
const char			*pf_output_extras(t_data *data, const char *format);
int					pf_output_noprint(t_data *data, const char *base);
int					pf_output_pointer(t_data *data, const char *base);
int					pf_output_signed(t_data *data, const char *base);
int					pf_output_string(t_data *data, const char *base);
int					pf_output_unsigned(t_data *data, const char *base);

#endif
