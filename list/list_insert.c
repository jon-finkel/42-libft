/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:45:18 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 21:42:59 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline void	ft_lstinsert(t_list **alst, t_list *newlink,
			int (*cmp)(void *, void *))
{
	t_list	*list;
	t_list	*tmp;

	list = *alst;
	if (!list || cmp(list->data, newlink->data))
		ft_lstadd(alst, newlink);
	else if (!list->next)
		list->next = newlink;
	else
	{
		while (list->next)
		{
			tmp = list;
			list = list->next;
			if (cmp(list->data, newlink->data))
			{
				newlink->next = list;
				tmp->next = newlink;
				return ;
			}
		}
		list->next = newlink;
	}
}
