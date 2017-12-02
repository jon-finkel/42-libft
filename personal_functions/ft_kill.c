/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:15:12 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 12:10:16 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_kill(const char *s, const int fd)
{
	if (s)
		ft_putendl_fd(s, fd);
	exit(EXIT_FAILURE);
}
