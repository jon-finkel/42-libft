/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:34:57 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:28:06 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./str.h"

void			ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}

void			ft_strclr(char *s)
{
	int			k;
	size_t		len;

	k = -1;
	len = ft_strlen(s);
	while ((unsigned int)++k < len)
		*(s + k) = '\0';
}
