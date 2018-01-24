/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:00:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:44:12 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			realloc_and_expand(const char *name, const char *value,
					size_t len)
{
	char			**env_copy;
	extern char		**environ;
	int				k;

	FAILZ(env_copy = (char **)malloc(sizeof(char *) * (len + 1)), -1);
	k = -1;
	while (environ[++k])
		FAILZ(env_copy[k] = ft_strdup(environ[k]), -1);
	EPICFAILZ(ft_asprintf(&env_copy[k], "%s=%s", name, value), -1);
	env_copy[++k] = NULL;
	ft_cleanup("A", environ);
	environ = env_copy;
	KTHXBYE;
}

int					ft_setenv(const char *name, const char *value,
					int overwrite)
{
	char			variable[4096];
	extern char		**environ;
	int				k;

	k = -1;
	while (environ[++k])
	{
		ft_memnccpy(variable, environ[k], '=', 4096);
		if (ft_strequ(variable, name))
		{
			if (overwrite)
			{
				free(environ[k]);
				EPICFAILZ(ft_asprintf(&environ[k], "%s=%s", name, value), -1);
			}
			KTHXBYE;
		}
	}
	GIMME(realloc_and_expand(name, value, (size_t)(k + 1)));
}
