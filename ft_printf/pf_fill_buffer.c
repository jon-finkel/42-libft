/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buffer_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 11:05:48 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/28 17:35:48 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_fill_buffer(t_buffer *buffer, const char filler,
			const char *s_filler, enum e_flags flag)
{
	char				*expand;
	char				*expanded_buffer;
	size_t				n;

	n = (s_filler ? ft_strlen(s_filler) : 1);
	if (flag == NON_PRINT)
		buffer->non_printable += n;
	*buffer->pf_len += n;
	while (*buffer->pf_len > buffer->size_factor * PRINTF_BUFFSIZE)
	{
		if (!(expand = ft_strnew(PRINTF_BUFFSIZE)))
			exit(EXIT_FAILURE);
		if (!(expanded_buffer = ft_strjoin(buffer->pf_buffer, expand)))
			exit(EXIT_FAILURE);
		free(buffer->pf_buffer);
		buffer->pf_buffer = expanded_buffer;
		free(expand);
		++buffer->size_factor;
	}
	if (!s_filler)
		*(buffer->pf_buffer + *buffer->pf_len - 1) = filler;
	else
		(void)ft_strncat(buffer->pf_buffer, s_filler, n);
}
