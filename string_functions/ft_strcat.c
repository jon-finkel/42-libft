/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:01:07 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 12:07:42 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strcat(char *restrict dst, const char *restrict src)
{
	char		*d;

	d = ft_strchr(dst, '\0');
	while ((*d++ = *src++))
		;
	return (dst);
}
