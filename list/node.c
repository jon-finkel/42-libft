/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:44:56 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 21:45:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

t_list			*ft_lstgetnode(const t_list *list, size_t n)
{
	++n;
	if (n > ft_lstsize(list))
		ZOMG;
	while (--n > 0)
		list = list->next;
	GIMME((t_list *)list);
}
