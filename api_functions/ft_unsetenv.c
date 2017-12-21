/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:00:50 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/21 15:41:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_unsetenv(const char *name)
{
	char			variable[512];
	extern char		**environ;
	int				k;

	if (!name || !*name || ft_strchr(name, '='))
		return (-1);
	k = -1;
	while (environ[++k])
	{
		ft_memset(variable, '\0', 512);
		ft_memnccpy(variable, environ[k], '=', 512);
		if (ft_strequ(name, variable))
		{
			while (environ[k + 1])
			{
				environ[k] = environ[k + 1];
				++k;
			}
			environ[k] = NULL;
		}
	}
	return (0);
}
