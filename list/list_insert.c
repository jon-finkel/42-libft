/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:45:18 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/19 20:30:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline void	ft_lstinsert(t_list **alst, t_list *newlink,
			int (*cmp)(const void *, const void *), enum e_sort sort)
{
	t_list	*list;
	t_list	*tmp;

	list = *alst;
	if (!list || (sort == E_REG && cmp(list->data, newlink->data))
		|| (sort == E_REV && !cmp(list->data, newlink->data)))
		return ft_lstadd(alst, newlink);
	while (list->next)
	{
		tmp = list;
		list = list->next;
		if ((sort == E_REG && cmp(list->data, newlink->data))
			|| (sort == E_REV && !cmp(list->data, newlink->data)))
		{
			newlink->next = list;
			tmp->next = newlink;
			return ;
		}
	}
	list->next = newlink;
}
