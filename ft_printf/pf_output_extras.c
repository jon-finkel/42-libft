/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_extras.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:42 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/03 17:17:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static int			k_conversion(t_printf *data)
{
	char		buff[26];
	char		*begin;
	char		*tm;
	time_t		time;

	ft_memset(buff, '\0', 26);
	time = va_arg(data->arg, time_t);
	PROTECT(tm = ft_ctime(&time), -1);
	begin = tm;
	if (NOT_FLAG(E_ALTERNATE, data->flags))
		ft_strcpy(buff, tm);
	else
	{
		ft_strncat(buff, tm, 3);
		ft_strcat(buff, ",");
		tm += 4;
		ft_strncat(buff, tm, 3);
		tm += 4;
		ft_strncat(buff, tm, 2);
	}
	ft_strdel(&begin);
	pf_fill_buffer(data, 0, buff, E_PRINT);
	return (0);
}

static void			n_conversion(t_printf *data)
{
	int		*ptr;

	ptr = (int *)va_arg(data->arg, void *);
	if (ptr)
		*ptr = (int)data->pf_len;
}

static int			t_conversion(t_printf *data)
{
	char		buff[9];
	char		*tm;
	int			k;
	time_t		time;

	ft_memset(buff, '\0', 9);
	time = va_arg(data->arg, time_t);
	PROTECT(tm = ft_ctime(&time), -1);
	k = 10;
	while (++k < 19)
		buff[k - 11] = tm[k];
	ft_strdel(&tm);
	pf_fill_buffer(data, 0, buff, E_PRINT);
	return (0);
}

static void			v_conversion(t_printf *data)
{
	char	*buff;
	char	*var;

	var = va_arg(data->arg, char *);
	if ((buff = ft_getenv(var)))
	{
		pf_fill_buffer(data, 0, buff, E_PRINT);
		free(buff);
	}
}

const char			*pf_output_extras(t_printf *data, const char *format)
{
	if (*format == 'k')
		NEG_PROTECT(k_conversion(data), NULL);
	else if (*format == 'n')
		n_conversion(data);
	else if (*format == 't')
		NEG_PROTECT(t_conversion(data), NULL);
	else
		v_conversion(data);
	return (format + 1);
}
