/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 09:51:28 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/06 09:14:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_putstr(const char *restrict s)
{
	if (!s)
		return ;
	write(STDOUT_FILENO, s, ft_strlen(s));
}
