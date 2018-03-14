/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:46:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:38:48 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

size_t			ft_lstsize(const t_list *list)
{
	size_t		size;

	size = 0;
	while (list)
	{
		list = list->next;
		++size;
	}
	GIMME(size);
}
