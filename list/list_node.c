/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:44:56 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:43:14 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline t_list	*ft_lstnode(const t_list *list, size_t n)
{
	while (n-- > 0)
	{
		list = list->next;
		if (!list)
			return (NULL);
	}
	return ((t_list *)list);
}
