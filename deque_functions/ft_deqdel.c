/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deqdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:28:55 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/18 15:30:31 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_deqdel(t_deque **adeq, t_dqtor dqtor)
{
	t_dlist		*head;
	t_dlist		*tmp;

	head = (*adeq)->head;
	while (head)
	{
		tmp = head;
		head = head->next;
		dqtor(tmp->data, tmp->data_size);
		free(tmp);
	}
	free(*adeq);
	*adeq = NULL;
}
