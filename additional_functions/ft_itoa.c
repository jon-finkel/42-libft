/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:28:58 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/22 12:43:27 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Converts an integer 'n' into an array of characters representing 'n'.
*/

char	*ft_itoa(int n)
{
	char			*tmp;
	char			*string;
	int				k;
	unsigned int	nb;

	if (!(tmp = ft_strnew(12)))
		return (NULL);
	tmp[0] = '0';
	k = -1;
	nb = (n < 0 ? -n : n);
	while (nb > 0)
	{
		tmp[++k] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		tmp[++k] = '-';
	if (!(string = ft_strrevcpy(tmp)))
		return (NULL);
	free(tmp);
	return (string);
}
