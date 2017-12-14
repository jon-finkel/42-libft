/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:24:25 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/14 17:13:00 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			**get_environ(char **environ)
{
	char		**env;
	size_t		len;

	len = 0;
	while (environ[len])
		++len;
	PROTECT(env = (char **)malloc(sizeof(char *) * (len + 1)), NULL);
	len = 0;
	while (environ[len])
	{
		PROTECT(env[len] = ft_strnew(ft_strlen(environ[len])), NULL);
		ft_strcpy(env[len], environ[len]);
		++len;
	}
	return (env);
}

char				*ft_getenv(const char *name)
{
	char			*buff;
	char			**env;
	extern char		**environ;
	int				k;
	size_t			len;

	buff = NULL;
	if (!environ || !name)
		return (NULL);
	PROTECT(env = get_environ(environ), NULL);
	len = ft_strlen(name);
	k = -1;
	while (env[++k])
		if (ft_strnequ((char *)(env[k]), name, len))
		{
			PROTECT(buff = ft_strnew(ft_strlen(env[k]) - len - 1), NULL);
			ft_strcpy(buff, ft_strchr(env[k], '=') + 1);
		}
	k = -1;
	while (env[++k])
		free(env[k]);
	free(env);
	return (buff);
}
