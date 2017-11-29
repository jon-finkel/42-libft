/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 18:17:58 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/28 17:58:21 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"

# define PRINTF_BUFFSIZE 4096

# define LAST_COLOR 17
# define LAST_CONVERSION 16
# define LAST_RANGE 6
# define LAST_TYPE (LAST_CONVERSION + 1)
# define MAX_LEN_INTMAX_T 20
# define MAX_LEN_BINARY_UINTMAX_T 64

# define LIST_CONTENT ((t_args *)(list->content))
# define NEXT_CONTENT ((t_args *)(list->next->content))
# define N_LIST_CONTENT ((t_args *)(n_list->content))
# define PF_BUFFER (((t_args *)(list->content))->buffer)

enum					e_flags
{
	FIELD_WIDTH,
	PRECISION,
	FIRST,
	SECOND,
	NATIVE,
	MODIFIED,
	LEFT,
	RIGHT,
	PRINT,
	NON_PRINT,
	NO_COLOR,
	COLOR
};

enum					e_type
{
	END,
	NOT_FLAG,
	SIGNED_ARG,
	UNSIGNED_ARG,
	POINTER
};

enum					e_range
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

typedef struct			s_buffer
{
	char				*pf_buffer;
	enum e_flags		flag;
	size_t				*pf_len;
	size_t				invalid;
	size_t				non_printable;
	unsigned int		size_factor;
}						t_buffer;

typedef struct			s_args
{
	void				*arg_data;
	union
	{
		intmax_t		s_nb;
		uintmax_t		u_nb;
	}					u_arg;
	int					field_width;
	int					precision;
	enum e_flags		zero_precision;
	short				alternate_form;
	short				negative;
	short				plus;
	short				space;
	short				zero;
	t_buffer			*buffer;
}						t_args;

struct					s_color
{
	char				*flag;
	size_t				len;
	char				*code;
};

struct					s_conv
{
	char				letter;
	void				(*f)(t_list *, const char *, enum e_range);
	const char			*base;
	enum e_range		range;
};

struct					s_type
{
	char				letter;
	enum e_type			data_type;
};

void					pf_fill_buffer(t_buffer *buffer, const char filler,
						const char *s_filler, enum e_flags flag);
t_list					*pf_get_flags(t_list *list, const char **format,
						enum e_flags flag);
const char				*pf_ansi_color(t_buffer *buffer, const char *format,
						int *k);
void					pf_initialize_list(t_list **alist, t_buffer *buffer,
						const char *format, va_list ap);
void					pf_output_char(t_list *list, const char *base,
						enum e_range range);
void					pf_output_noprint(t_list *list, const char *base,
						enum e_range range);
void					pf_output_pointer(t_list *list, const char *base,
						enum e_range range);
void					pf_output_signed(t_list *list, const char *base,
						enum e_range range);
void					pf_output_string(t_list *list, const char *ph,
						enum e_range range);
void					pf_output_unsigned(t_list *list, const char *base,
						enum e_range range);

#endif
