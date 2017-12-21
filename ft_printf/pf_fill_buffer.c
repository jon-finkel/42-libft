/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_fill_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:45:40 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/21 18:15:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static void			printf_fill(t_data *data, const char filler,
					const char *s_filler, size_t n)
{
	int			k;

	data->pf_len += n;
	if (data->index + n > PRINTF_BUFFSIZE)
	{
		data->pf_buffer[data->index + 1] = '\0';
		write(data->fd, data->pf_buffer, data->index);
		data->index = 0;
		if (n > PRINTF_BUFFSIZE)
		{
			ft_putstr(s_filler);
			return ;
		}
	}
	if (!s_filler)
		data->pf_buffer[data->index++] = filler;
	else
	{
		k = -1;
		while ((unsigned int)++k < n)
			data->pf_buffer[data->index++] = s_filler[k];
	}
}

static void			sprintf_fill(t_data *data, const char filler,
					const char *s_filler, size_t n)
{
	int			k;

	if (!s_filler && data->index-- > 0)
		data->pf_buffer[data->pf_len++] = filler;
	else if (s_filler)
	{
		n = _MIN(n, data->index);
		data->index -= n;
		k = -1;
		while ((unsigned int)++k < n)
			data->pf_buffer[data->pf_len++] = s_filler[k];
	}
}

static void			asprintf_fill(t_data *data, const char filler,
					const char *s_filler, size_t n)
{
	int			k;
	size_t		size;

	if (data->pf_len + n > data->realloc_factor * ASPRINTF_BUFFSIZE)
	{
		++data->realloc_factor;
		size = data->realloc_factor * ASPRINTF_BUFFSIZE;
		EXIT_PROTECT(data->pf_buffer = ft_realloc(data->pf_buffer, size + 1));
	}
	if (!s_filler)
		data->pf_buffer[data->pf_len++] = filler;
	else
	{
		k = -1;
		while ((unsigned int)++k < n)
			data->pf_buffer[data->pf_len++] = s_filler[k];
	}
}

void				pf_fill_buffer(t_data *data, const char filler,
					const char *s_filler, enum e_flags flag)
{
	size_t		n;

	n = (s_filler ? ft_strlen(s_filler) : 1);
	if (flag == NON_PRINT)
		data->non_printable += n;
	if (data->pf_type == PRINTF)
		return (printf_fill(data, filler, s_filler, n));
	else if (data->pf_type == SPRINTF)
		return (sprintf_fill(data, filler, s_filler, n));
	else
		return (asprintf_fill(data, filler, s_filler, n));
}
