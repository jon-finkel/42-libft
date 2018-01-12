/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:58:14 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/12 21:43:45 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_putenv(char *string)
{
	char		name[1024];
	char		*value;

	if (!string || !(value = ft_strchr(string, '=')))
		ONOES;
	ft_memnccpy(name, string, '=', 1024);
	EPICFAILZ(ft_setenv(name, value + 1, 1), -1);
	KTHXBYE;
}
