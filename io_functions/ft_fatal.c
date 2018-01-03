/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 16:46:11 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/03 19:36:36 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_fatal(const char *s)
{
	if (s)
		ft_dprintf(STDERR_FILENO, "fatal: %s\n", s);
	exit(EXIT_FAILURE);
}
