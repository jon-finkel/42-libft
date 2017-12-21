/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:00:38 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/21 00:10:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			rewrite_variable(const char *value, int k, int overwrite)
{
	(void)value;
	(void)k;
	(void)overwrite;
	return (0);
}

int					ft_setenv(const char *name, const char *value,
					int overwrite)
{
	char			variable[512];
	extern char		**environ;
	int				k;
	int				p;
	size_t			len;

	k = -1;
	while (environ[++k])
	{
		ft_memset(variable, '\0', 512);
		ft_memnccpy(variable, environ[k], '=', 512);
		if (ft_strequ(name, variable))
			return (rewrite_variable(value, k, overwrite));
	}
	ft_sprintf(variable, "%s=%s", name, value);
	len = ft_strlen(environ[k - 1]);
	environ[k] = environ[k - 1] + len + 1;
	p = -1;
	while (variable[++p])
		environ[k - 1][++len] = variable[p];
	environ[k - 1][++len] = '\0';
	environ[k + 1] = NULL;
	return (0);
}
