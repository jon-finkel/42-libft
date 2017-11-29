/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ansi_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:21:42 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/28 18:21:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static const struct s_color	g_color[] =
{
	{"{eoc}", 5, "\033[0m"},
	{"{black}", 7, "\033[30m"},
	{"{red}", 5, "\033[31m"},
	{"{green}", 7, "\033[32m"},
	{"{yellow}", 8, "\033[33m"},
	{"{blue}", 6, "\033[34m"},
	{"{magenta}", 9, "\033[35m"},
	{"{cyan}", 6, "\033[36m"},
	{"{white}", 7, "\033[37m"},
	{"{bright_black}", 14, "\033[1;30m"},
	{"{bright_red}", 12, "\033[1;31m"},
	{"{bright_green}", 14, "\033[1;32m"},
	{"{bright_yellow}", 15, "\033[1;33m"},
	{"{bright_blue}", 13, "\033[1;34m"},
	{"{bright_magenta}", 16, "\033[1;35m"},
	{"{bright_cyan}", 13, "\033[1;36m"},
	{"{bright_white}", 14, "\033[1;37m"},
};

const char				*pf_ansi_color(t_buffer *buffer, const char *format,
						int *k)
{
	int			p;

	p = -1;
	while (++p < LAST_COLOR)
		if (ft_strnequ(format, g_color[p].flag, g_color[p].len) == 1)
		{
			pf_fill_buffer(buffer, 0, g_color[p].code, NON_PRINT);
			buffer->flag = (p == 0 ? NO_COLOR : COLOR);
			format += g_color[p].len;
			*k += g_color[p].len;
			break ;
		}
	if (p == LAST_COLOR)
	{
		pf_fill_buffer(buffer, '{', NULL, PRINT);
		++format;
	}
	return (format);
}
