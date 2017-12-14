/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 18:17:58 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/13 16:44:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"

# define PRINTF_BUFFSIZE 4096
# define ASPRINTF_BUFFSIZE 128

# define LAST_COLOR 17
# define LAST_CONVERSION 18
# define MAX_LEN_INTMAX_T 20
# define MAX_LEN_BINARY_UINTMAX_T 64
# define MAX_LEN_POINTER 18

enum				e_flags
{
	ALTERNATE = 1,
	NEGATIVE = 2,
	PLUS = 4,
	SPACE = 8,
	ZERO = 16,
	PRECISION_CHANGED = 32,
	FIRST,
	SECOND,
	PRINT,
	NON_PRINT,
	PRINTF,
	SPRINTF,
	ASPRINTF
};

enum				e_range
{
	VOID = 0,
	INT = 1,
	CHAR = 2,
	SHORT = 3,
	SIZE_T = 4,
	LONG = 5,
	LONG_LONG = 6,
	INTMAX_T = 7
};

typedef struct		s_data
{
	enum e_flags	pf_type;
	char			*pf_buffer;
	size_t			realloc_factor;
	size_t			pf_len;
	int				fd;
	size_t			index;
	size_t			non_printable;
	enum e_range	range;
	char			error;
	char			c;
	char			flags;
	int				field_width;
	int				precision;
	va_list			ap;
}					t_data;

struct				s_color
{
	char			*flag;
	size_t			len;
	char			*code;
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
const char			*pf_ansi_color(t_data *data, const char *format);
void				pf_buff_format(t_data *data, const char *format);
int					pf_output_char(t_data *data, const char *base);
int					pf_output_double(t_data *data, const char *base);
int					pf_output_noprint(t_data *data, const char *base);
int					pf_output_pointer(t_data *data, const char *base);
int					pf_output_signed(t_data *data, const char *base);
int					pf_output_string(t_data *data, const char *sub);
int					pf_output_unsigned(t_data *data, const char *base);

#endif
