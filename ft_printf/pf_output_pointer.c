/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 10:49:46 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/02 20:05:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			apply_field_width(t_list *list, char *address)
{
	int			field_width;
	size_t		len;

	field_width = LIST_CONTENT->field_width;
	len = ft_strlen(address);
	if (LIST_CONTENT->field_width > 0)
		while ((unsigned int)field_width-- > len)
			pf_fill_buffer(PF_BUFFER, ' ', NULL, PRINT);
	pf_fill_buffer(PF_BUFFER, 0, address, PRINT);
	free(address);
	address = NULL;
	if (LIST_CONTENT->field_width < 0)
	{
		field_width = -field_width;
		while ((unsigned int)field_width-- > len)
			pf_fill_buffer(PF_BUFFER, ' ', NULL, PRINT);
	}
}

static void			apply_zero_width(t_list *list, char *s, size_t len)
{
	char		*address;
	int			k;
	int			zero_width;

	EXIT_PROTECT(address = ft_strnew(LIST_CONTENT->field_width));
	zero_width = LIST_CONTENT->field_width - len - 2;
	k = -1;
	address[++k] = '0';
	address[++k] = 'x';
	while (zero_width-- > 0)
		address[++k] = '0';
	ft_strcpy(address + k + 1, s);
	pf_fill_buffer(PF_BUFFER, 0, address, PRINT);
	free(address);
}

static void			apply_precision(t_list *list, char *s, int precision,
					size_t len)
{
	char		*address;
	int			k;

	if (LIST_CONTENT->zero == 1 && LIST_CONTENT->field_width > (int)len + 2)
		return (apply_zero_width(list, s, len));
	EXIT_PROTECT(address = ft_strnew(precision + 2));
	precision -= len;
	k = -1;
	address[++k] = '0';
	address[++k] = 'x';
	while (precision-- > 0)
		address[++k] = '0';
	ft_strcpy(address + k + 1, s);
	apply_field_width(list, address);
}

void				pf_output_pointer(t_list *list, const char *base,
					enum e_range range)
{
	char			tmp[MAX_LEN_INTMAX_T];
	int				k;
	int				prec;
	intptr_t		nb;

	(void)range;
	nb = (intptr_t)LIST_CONTENT->arg_data;
	k = -1;
	if (!nb && LIST_CONTENT->zero_precision == NATIVE)
		tmp[++k] = '0';
	while (nb > 0)
	{
		tmp[++k] = base[nb % 16];
		nb /= 16;
	}
	tmp[++k] = '\0';
	prec = (LIST_CONTENT->precision != INT_MAX ? LIST_CONTENT->precision : 0);
	apply_precision(list, ft_strrev(tmp), prec, ft_strlen(tmp));
}
