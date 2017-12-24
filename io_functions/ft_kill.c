/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:15:12 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/24 11:15:30 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_kill(const char *s)
{
	if (s)
		ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
