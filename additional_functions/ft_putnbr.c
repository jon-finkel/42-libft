/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 09:59:27 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/21 17:23:20 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int n)
{
	char			buff[12];
	int				k;
	unsigned int	nb;

	nb = (n < 0 ? -n : n);
	k = -1;
	if (n == 0)
		buff[++k] = '0';
	while (nb > 0)
	{
		buff[++k] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		buff[++k] = '-';
	buff[++k] = '\0';
	write(STDOUT_FILENO, ft_strrev(buff), ft_strlen(buff));
}
