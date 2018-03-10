/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:28:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/10 16:24:04 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"
#include "../str/str.h"

static void			cleanup_pointers_array(char ***aarray)
{
	char		**aptr;
	int			k;

	aptr = *aarray;
	k = -1;
	while (aptr[++k])
	{
		free(aptr[k]);
		aptr[k] = NULL;
	}
	free(aptr);
	aptr = NULL;
}

void				ft_cleanup(const char *args, ...)
{
	va_list		ap;

	va_start(ap, args);
	while (*args)
	{
		if (*args == 'P')
			ft_strdel(va_arg(ap, char **));
		else if (*args == 'A')
			cleanup_pointers_array(va_arg(ap, char ***));
		++args;
	}
	va_end(ap);
}

void				ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
