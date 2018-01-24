/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:30:52 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/23 19:56:14 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

void			ft_bzero(void *s, size_t n)
{
	int		k;

	k = -1;
	while ((unsigned int)++k < n)
		((unsigned char *)s)[k] = '\0';
}
