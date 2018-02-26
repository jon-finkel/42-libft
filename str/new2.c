/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:33:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/26 04:34:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./str.h"
#include "../mem/mem.h"

char		*ft_strnew(size_t size)
{
	GIMME((char *)ft_memalloc(sizeof(char) * (size + 1)));
}

int			ft_strrewrite(char *restrict big, const char *restrict little,
			const char *fill)
{
	char		*copy;
	int			k;
	size_t		big_len;
	size_t		lit_len;

	lit_len = ft_strlen(little);
	big_len = ft_strlen(big);
	little = ft_strstr(big, little);
	copy = ft_strdup(little + lit_len);
	big += big_len - ft_strlen(little);
	while (*fill)
		*big++ = *fill++;
	k = -1;
	while (copy[++k])
		*big++ = copy[k];
	*big = '\0';
	free(copy);
	KTHXBYE;
}
