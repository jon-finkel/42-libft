/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 11:57:35 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:29:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

char			*ft_strrev(char *const s)
{
	char		c;
	int			k;
	size_t		len;

	k = -1;
	len = ft_strlen(s);
	while ((unsigned int)++k < len--)
	{
		c = s[k];
		s[k] = s[len];
		s[len] = c;
	}
	GIMME(s);
}
