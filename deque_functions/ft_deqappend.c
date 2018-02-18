/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:26:39 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/18 08:51:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_deqappend(t_deque *deque, t_dlist *newlink)
{
	if (deque->tail)
		deque->tail->next = newlink;
	else
		deque->head = newlink;
	newlink->prev = deque->tail;
	deque->tail = newlink;
}
