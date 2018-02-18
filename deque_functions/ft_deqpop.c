/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:32:50 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/18 14:49:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_deqpop(t_deque *deque, t_dqtor dqtor)
{
	t_dlist		*tmp;

	tmp = deque->head;
	deque->head = tmp->next;
	if (deque->head)
		deque->head->prev = NULL;
	else
		deque->tail = NULL;
	dqtor(tmp->data, tmp->data_size);
	free(tmp);
	tmp = NULL;
}
