/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 22:06:41 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/22 15:44:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/io.h"
#include "libft/opt.h"
#include "libft/str.h"

static int	show_err(int err, char *name, char *option, size_t len)
{
	if (!err)
		return (0);
	if (err == UNKNOWN_OPTION)
		ft_dprintf(STDERR_FILENO, "%s: illegal option -- %.*s\n",
			name, (unsigned)len, option);
	else if (err == NO_OPT)
		ft_dprintf(STDERR_FILENO, "%s: argument required -- %.*s\n",
			name, (unsigned)len, option);
	return (1);
}

static int	get_value(char **c_opt, const t_opt opts[], char *optv[], int i[2])
{
	char	*opt;
	char	*value;

	opt = *c_opt + i[1];
	if (opts->type == FT_OPT_BOOLEAN)
		*(int *)opts->value ^= opts->flag;
	else if (opts->type == FT_OPT_STRING || opts->type == FT_OPT_INTEGER)
	{
		value = NULL;
		if (*opt == '=')
		{
			value = opt + 1;
			*c_opt += i[1] + ft_strlen(opt) - 1;
		}
		else if (!*opt)
			value = optv[++i[0]];
		if (!value)
			return (NO_OPT);
		if (opts->type == FT_OPT_STRING)
			*(char **)opts->value = value;
		else if (opts->type == FT_OPT_INTEGER)
			*(int *)opts->value = 0;
	}
	return (0);
}

static int	parse_short(char **c_opt, const t_opt opt[], char *optv[], int *i)
{
	int	indexes[2];
	int	err;

	while (opt->type != FT_OPT_END)
	{
		if (opt->short_name == **c_opt)
		{
			indexes[0] = *i;
			indexes[1] = 1;
			err = get_value(c_opt, opt, optv, indexes);
			*i = *indexes;
			return (show_err(err, optv[0], *c_opt - 1, 1));
		}
		opt++;
	}
	return (show_err(UNKNOWN_OPTION, optv[0], *c_opt, 1));
}

static int	parse_long(char **c_opt, const t_opt opt[], char *optv[], int *i)
{
	size_t	len;
	char	*res;
	int		indexes[2];
	int		err;

	if ((res = ft_strchr(*c_opt, '=')))
	{
		len = res - *c_opt;
	}
	else
		len = ft_strlen(*c_opt);
	while (opt->type != FT_OPT_END)
	{
		if (ft_strncmp(opt->long_name, *c_opt, len) == 0)
		{
			indexes[0] = *i;
			indexes[1] = (int)len;
			err = get_value(c_opt, opt, optv, indexes);
			*i = *indexes;
			return (show_err(err, optv[0], *c_opt - len, len));
		}
		opt++;
	}
	return (show_err(UNKNOWN_OPTION, optv[0], *c_opt, ft_strlen(*c_opt)));
}

int			ft_optparse(const t_opt opts[], int *index, int optc, char *optv[])
{
	int		err;
	char	*opt;
	char	*s_opt;

	err = 0;
	while (*index < optc)
	{
		opt = optv[*index];
		s_opt = opt;
		if (opt[0] != '-' || !opt[1])
			break ;
		if (opt[1] != '-')
			while (*++s_opt)
				err |= parse_short(&s_opt, opts, optv, index);
		else if (!opt[2])
		{
			++*index;
			break ;
		}
		else if (s_opt += 2)
			err |= parse_long(&s_opt, opts, optv, index);
		++*index;
	}
	return (err ? -1 : 0);
}
