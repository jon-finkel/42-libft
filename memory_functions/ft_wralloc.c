/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wralloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:36:18 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 19:50:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"
#include "../handlers/handlers.h"

void			*ft_wralloc(size_t size)
{
	extern int		errno;
	void			*ptr;

	if (!(ptr = malloc(size)))
		FT_ERRHDL(errno);
	GIMME(ptr);
}
