/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:21:13 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/18 08:51:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_deqadd(t_deque *deque, t_dlist *newlink)
{
	if (deque->head)
		deque->head->prev = newlink;
	else
		deque->tail = newlink;
	newlink->next = deque->head;
	deque->head = newlink;
}
