/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:36:22 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:21:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline void	ft_lstsnipe(t_list **alst, t_list *target, t_ldtor ldtor, ...)
{
	t_list	*list;
	va_list	ap;

	va_start(ap, ldtor);
	if (*alst == target)
	{
		*alst = target->next;
		ldtor(target->data, target->data_size, ap);
	}
	else
	{
		list = *alst;
		while (list->next != target)
			list = list->next;
		list->next = target->next;
		ldtor(target->data, target->data_size, ap);
	}
	va_end(ap);
}

inline void	ft_deqpop(t_deque *deque, t_dqtor dqtor, ...)
{
	t_dlist	*tmp;
	va_list	ap;

	va_start(ap, dqtor);
	tmp = deque->head;
	deque->head = tmp->next;
	if (deque->head)
		deque->head->prev = NULL;
	else
		deque->tail = NULL;
	dqtor(tmp->data, tmp->data_size, ap);
	va_end(ap);
	free(tmp);
	tmp = NULL;
}

inline void	ft_deqeject(t_deque *deque, t_dqtor dqtor, ...)
{
	t_dlist	*tmp;
	va_list	ap;

	va_start(ap, dqtor);
	tmp = deque->tail;
	deque->tail = tmp->prev;
	if (deque->tail)
		deque->tail->next = NULL;
	else
		deque->head = NULL;
	dqtor(tmp->data, tmp->data_size, ap);
	va_end(ap);
	free(tmp);
	tmp = NULL;
}
