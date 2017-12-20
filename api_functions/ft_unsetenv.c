/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:00:50 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/20 20:42:50 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_unsetenv(const char *name)
{
	extern char		**environ;
	int				k;
	size_t			len;

	k = -1;
	while (environ[++k])
		if (ft_strequ(name, environ[k]))
		{
			free(environ[k]);
			environ[k] = NULL;
			while (environ[++k])
			{
				len = ft_strlen(environ[k]);
				PROTECT(environ[k - 1] = ft_strnew(len), -1);
				ft_memmove(environ[k - 1], environ[k], len);
				free(environ[k]);
				environ[k] = NULL;
			}
			break ;
		}
	return (0);
}
