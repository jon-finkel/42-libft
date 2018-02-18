/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqeject.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:27:35 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/18 09:39:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_deqeject(t_deque *deque, t_dqtor dqtor)
{
	t_dlist		*tmp;

	tmp = deque->tail;
	deque->tail = tmp->prev;
	if (deque->tail)
		deque->tail->next = NULL;
	else
		deque->head = NULL;
	dqtor(tmp->data, tmp->data_size);
}
