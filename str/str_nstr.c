/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_nstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 17:26:01 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:50:12 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline char	*ft_strnstr(const char *restrict big, const char *restrict little,
			size_t n)
{
	size_t	len;

	if (!*little)
		return ((char *)big);
	len = ft_strlen(little);
	while (n && *big)
	{
		if (len <= n && ft_strncmp(big, little, len) == 0)
			return ((char *)big);
		++big;
		--n;
	}
	return (NULL);
}
