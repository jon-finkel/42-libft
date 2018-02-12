/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:50:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:28:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

char			*ft_strndup(const char *s, size_t n)
{
	char		*str;

	str = ft_strnew(n);
	str = ft_strncpy(str, (char *)s, n);
	str[n] = '\0';
	GIMME(str);
}
