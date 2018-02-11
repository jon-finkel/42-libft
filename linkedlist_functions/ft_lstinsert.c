/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 14:21:53 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/11 14:23:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

inline void			ft_lstinsert(t_list **alst, t_list *newlink,
					int (*del)(void *, void *))
{
	t_list		*list;
	t_list		*tmp;

	list = *alst;
	if (!list || del(list->data, newlink->data))
		ft_lstadd(alst, newlink);
	else if (!list->next)
		list->next = newlink;
	else
	{
		while (list->next)
		{
			tmp = list;
			list = list->next;
			if (del(list->data, newlink->data))
			{
				newlink->next = list;
				tmp->next = newlink;
				BYEZ;
			}
		}
		list->next = newlink;
	}
}
