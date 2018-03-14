/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:27:00 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 10:37:53 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

void			ft_lstadd(t_list **alst, t_list *newlink)
{
	newlink->next = *alst;
	*alst = newlink;
}

void			ft_dlstadd(t_dlist **adlst, t_dlist *newlink)
{
	if (*adlst)
		(*adlst)->prev = newlink;
	newlink->next = *adlst;
	*adlst = newlink;
}

void			ft_deqadd(t_deque *deque, t_dlist *newlink)
{
	if (deque->head)
		deque->head->prev = newlink;
	else
		deque->tail = newlink;
	newlink->next = deque->head;
	deque->head = newlink;
}
