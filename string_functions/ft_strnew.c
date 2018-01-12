/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:33:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/12 15:38:32 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_strnew(size_t size)
{
	char		*dst;
	int			k;

	FAILZ(dst = (char *)malloc(sizeof(char) * (size + 1)), NULL);
	k = -1;
	while ((unsigned int)++k <= size)
		*(dst + k) = '\0';
	return (dst);
}
