/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 04:34:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 21:46:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

int				ft_atoi(const char *str)
{
	int						neg;
	unsigned long long		sum;

	neg = 1;
	sum = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg = -1;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10uLL + (unsigned long long)(*str - 48);
		if (sum > (unsigned long long)LLONG_MAX)
			GIMME(neg < 0 ? 0 : -1);
		++str;
	}
	GIMME(neg * (int)sum);
}

char			*ft_itoa(int n)
{
	char				tmp[13];
	char				*string;
	int					k;
	unsigned int		nb;

	k = -1;
	if (!n)
		tmp[++k] = '0';
	nb = (n < 0 ? -n : n);
	while (nb > 0)
	{
		tmp[++k] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		tmp[++k] = '-';
	tmp[++k] = '\0';
	string = ft_strrevcpy(tmp);
	GIMME(string);
}
