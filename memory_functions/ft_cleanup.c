/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:40:20 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/23 19:56:39 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string_functions/string_private.h"

static void			cleanup_pointers_array(char **aptr)
{
	int			k;

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
	char			*ptr;
	char			**aptr;
	va_list			ap;

	va_start(ap, args);
	while (args && *args)
	{
		if (*args == 'P')
		{
			ptr = va_arg(ap, char *);
			ft_strdel(&ptr);
		}
		else if (*args == 'A')
		{
			aptr = va_arg(ap, char **);
			cleanup_pointers_array(aptr);
		}
		++args;
	}
	va_end(ap);
}
