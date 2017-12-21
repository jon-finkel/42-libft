/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:00:38 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/21 15:45:04 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			extend_and_rewrite(const char *value, char *ptr, size_t len,
					int k)
{
	extern char		**environ;
	int				p;
	size_t			p_len;

	p = k;
	while (environ[p + 1])
		++p;
	while (p != k)
	{
		p_len = ft_strlen(environ[p]);
		ft_memmove(environ[p] + len, environ[p], p_len);
		environ[p] += len;
		environ[p][p_len] = '\0';
		--p;
	}
	ft_strcpy(ptr, value);
	return (0);
}

static int			rewrite_variable(const char *name, const char *value, int k)
{
	char			*ptr;
	extern char		**environ;
	ssize_t			len;

	ptr = ft_strchr(environ[k], '=') + 1;
	len = ft_strlen(environ[k]) - (ft_strlen(name) + ft_strlen(value) + 1);
	if (!len)
		ft_strcpy(ptr, value);
	else if (len > 0)
		ft_strcpy(ptr, value);
	else
		return (extend_and_rewrite(value, ptr, -len, k));
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

	if (!name || !*name || ft_strchr(name, '='))
		return (-1);
	k = -1;
	while (environ[++k])
	{
		ft_memset(variable, '\0', 512);
		ft_memnccpy(variable, environ[k], '=', 512);
		if (ft_strequ(name, variable))
			return ((overwrite ? rewrite_variable(name, value, k) : 0));
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
