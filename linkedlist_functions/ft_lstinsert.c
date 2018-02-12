/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 14:21:53 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:53:24 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

void			ft_lstinsert(t_list **alst, t_list *newlink,
				int (*cmp)(void *, void *))
{
	t_list		*list;
	t_list		*tmp;

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
				BYEZ;
			}
		}
		list->next = newlink;
	}
}
