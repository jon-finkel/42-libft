/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:26:39 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/16 20:27:25 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_deqappend(t_deque *deque, t_dlist *newlink)
{
	deque->tail->next = newlink;
	newlink->prev = deque->tail;
	deque->tail = newlink;
}
