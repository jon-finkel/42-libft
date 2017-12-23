/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 19:40:20 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/23 21:28:25 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void			cleanup_pointers_array(char **aptr)
{
	int		k;

	k = -1;
	while (aptr[++k])
		free(aptr[k]);
	free(aptr);
}

void				ft_cleanup(const int nb, ...)
{
	char			*ptr;
	char			**aptr;
	enum e_type		type;
	int				k;
	va_list			ap;

	k = -1;
	va_start(ap, nb);
	while (++k < nb)
	{
		type = (enum e_type)va_arg(ap, int);
		if (type == E_PTR)
		{
			ptr = va_arg(ap, char *);
			free(ptr);
		}
		else
		{
			aptr = va_arg(ap, char **);
			cleanup_pointers_array(aptr);
		}
		++k;
	}
	va_end(ap);
}
