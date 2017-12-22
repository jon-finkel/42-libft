/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_ansi_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:34:16 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/23 00:02:50 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_private.h"

static const struct s_color		g_color[] =
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

static int			check_end_of_color_flag(const char *format)
{
	while (*format)
	{
		if (ft_strnequ(format, "{eoc}", 5))
			return (1);
		++format;
	}
	return (0);
}

const char			*pf_ansi_color(t_data *data, const char *format)
{
	int		k;

	k = -1;
	while (++k < LAST_COLOR)
		if (ft_strnequ(format, g_color[k].flag, g_color[k].len))
		{
			if (!check_end_of_color_flag(format))
			{
				k = LAST_COLOR;
				break ;
			}
			pf_fill_buffer(data, 0, g_color[k].code, NON_PRINT);
			format += g_color[k].len;
			break ;
		}
	if (k == LAST_COLOR)
	{
		pf_fill_buffer(data, '{', NULL, PRINT);
		++format;
	}
	return (format);
}
