/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:24:48 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/01 11:49:28 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_putendl(const char *s)
{
	if (!s)
		return ;
	write(STDOUT_FILENO, s, ft_strlen(s));
	ft_putchar('\n');
}
