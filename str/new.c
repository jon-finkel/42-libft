/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:33:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 22:36:11 by nfinkel          ###   ########.fr       */
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

int			ft_atoi(const char *str)
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

char		*ft_itoa(int n)
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
