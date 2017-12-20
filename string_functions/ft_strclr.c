/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 17:15:13 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 11:50:13 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_strclr(char *s)
{
	int			k;
	size_t		len;

	if (!s)
		return ;
	k = -1;
	len = ft_strlen(s);
	while ((unsigned int)++k < len)
		*(s + k) = '\0';
}
