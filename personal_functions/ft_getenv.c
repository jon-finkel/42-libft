/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:24:25 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/13 19:21:10 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_getenv(const char *name)
{
	char		*buff;
	char		**env;
	int			k;
	size_t		len;

	buff = NULL;
	env = g_environ;
	len = ft_strlen(name);
	k = -1;
	while (env[++k])
		if (ft_strnequ((char *)(env[k]), name, len))
			PROTECT(ft_asprintf(&buff, "%s", ft_strchr(env[k], '=') + 1), NULL);
	return (buff);
}
