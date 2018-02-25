/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:56:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:31:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

int			ft_strcmp(const char *restrict s1, const char *restrict s2)
{
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	GIMME((unsigned char)*s1 - (unsigned char)*s2);
}

int			ft_strncmp(const char *restrict s1, const char *restrict s2,
			size_t n)
{
	if (!n)
		KTHXBYE;
	while (--n && *s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		++s1;
		++s2;
	}
	GIMME(*(unsigned char *)s1 - *(unsigned char *)s2);
}

int			ft_strequ(const char *restrict s1, const char *restrict s2)
{
	while (*s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		++s1;
		++s2;
	}
	GIMME(*s1 == *s2 ? 1 : 0);
}

int			ft_strnequ(const char *restrict s1, const char *restrict s2,
			size_t n)
{
	if (!n)
		GIMME(1);
	while (--n && *s1 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		++s1;
		++s2;
	}
	GIMME(*s1 == *s2 ? 1 : 0);
}
