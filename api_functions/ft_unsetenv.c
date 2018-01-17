/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:00:50 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/01 16:09:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Do not use on original environ array, make a copy of it and then, use it
** on the copy. If used on original environ array, the behavior is undefined.
*/

static int			copy_and_relocate(size_t len, int n)
{
	char			**env_copy;
	extern char		**environ;
	char			***aenv;
	int				k;
	int				p;

	PROTECT(env_copy = (char **)malloc(sizeof(char *) * (len)), -1);
	k = -1;
	p = -1;
	while ((unsigned int)++k < len - 1)
	{
		if (k == n)
			++p;
		PROTECT(env_copy[k] = ft_strdup(environ[++p]), -1);
	}
	env_copy[k] = NULL;
	aenv = &environ;
	ft_cleanup("A", environ);
	*aenv = env_copy;
	return (0);
}

int					ft_unsetenv(const char *name)
{
	char			variable[4096];
	extern char		**environ;
	int				k;
	size_t			len;

	k = -1;
	while (environ[++k])
	{
		ft_memnccpy(variable, environ[k], '=', 4096);
		if (ft_strequ(variable, name))
		{
			len = k;
			while (environ[len])
				++len;
			return (copy_and_relocate(len, k));
		}
	}
	return (0);
}
