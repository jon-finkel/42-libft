/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:28:55 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/20 09:47:35 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_deqdel(t_deque **adeq, t_dqtor dqtor, ...)
{
	t_dlist		*head;
	t_dlist		*tmp;
	va_list		ap;
	va_list		cpy;

	va_start(ap, dqtor);
	head = (*adeq)->head;
	while (head)
	{
		tmp = head;
		head = head->next;
		va_copy(cpy, ap);
		dqtor(tmp->data, tmp->data_size, ap);
		va_end(cpy);
		free(tmp);
	}
	va_end(ap);
	free(*adeq);
	*adeq = NULL;
}
