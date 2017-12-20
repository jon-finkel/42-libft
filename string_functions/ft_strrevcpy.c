/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrevcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 11:42:29 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/02 20:09:50 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strrevcpy(const char *const s)
{
	char		*start;
	char		*string;
	size_t		len;

	len = ft_strlen(s);
	PROTECT(string = ft_strnew(len), NULL);
	start = string;
	while (len > 0)
		*string++ = s[--len];
	*string = '\0';
	return (start);
}
