/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:01:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:23:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

char			*ft_strcat(char *restrict dst, const char *restrict src)
{
	char		*d;

	d = ft_strchr(dst, '\0');
	while ((*d++ = *src++))
		;
	GIMME(dst);
}
