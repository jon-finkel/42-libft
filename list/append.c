/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:27:54 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 21:38:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./list.h"

void		ft_lstappend(t_list *restrict list, t_list *restrict newlink)
{
	while (list->next)
		list = list->next;
	list->next = newlink;
}

void		ft_dlstappend(t_dlist *restrict dlist, t_dlist *restrict newlink)
{
	while (dlist->next)
		dlist = dlist->next;
	dlist->next = newlink;
	newlink->prev = dlist;
}

void		ft_deqappend(t_deque *deque, t_dlist *newlink)
{
	if (deque->tail)
		deque->tail->next = newlink;
	else
		deque->head = newlink;
	newlink->prev = deque->tail;
	deque->tail = newlink;
}
