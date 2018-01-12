/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 18:41:21 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/12 21:48:45 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		KTHXBYE;
	if (n == 0)
		return (1);
	while (--n && *s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		++s1;
		++s2;
	}
	return (*s1 == *s2 ? 1 : 0);
}
