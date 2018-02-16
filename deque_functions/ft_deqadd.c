/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 20:21:13 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/16 20:26:25 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_deqadd(t_deque *deque, t_dlist *newlink)
{
	deque->head->prev = newlink;
	newlink->next = deque->head;
	deque->head = newlink;
}
