/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 22:00:32 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/02 20:14:21 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"


void					ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void					ft_putnbr_fd(int n, int fd)
{
	char				buff[12];
	int					k;
	unsigned int		nb;

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
	write(fd, ft_strrev(buff), ft_strlen(buff));
}

void					ft_putstr_fd(const char *restrict s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void					ft_putendl_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	ft_putchar_fd('\n', fd);
}

_Noreturn void			ft_fatal(const char *restrict s, const int errcode)
{
	ft_putstr_fd("fatal: ", STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	exit(errcode);
}
