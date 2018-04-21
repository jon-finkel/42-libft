/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 21:29:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/21 21:21:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/list.h"

inline void	ft_lstdelone(t_list **alst, t_ldtor ldtor, va_list ap)
{
	ldtor((*alst)->data, (*alst)->data_size, ap);
	free(*alst);
	*alst = NULL;
}

inline void	ft_lstdel(t_list **alst, t_ldtor ldtor, ...)
{
	t_list	*tmp;
	va_list	ap;
	va_list	cpy;

	va_start(ap, ldtor);
	tmp = *alst;
	while (*alst)
	{
		tmp = (*alst)->next;
		va_copy(cpy, ap);
		ft_lstdelone(&(*alst), ldtor, cpy);
		va_end(cpy);
		*alst = tmp;
	}
	va_end(ap);
	alst = NULL;
}

inline void	ft_deqdel(t_deque **adeq, t_dqtor dqtor, ...)
{
	t_dlist	*tmp;
	va_list	ap;
	va_list	cpy;

	va_start(ap, dqtor);
	while ((*adeq)->head)
	{
		tmp = (*adeq)->head;
		(*adeq)->head = (*adeq)->head->next;
		va_copy(cpy, ap);
		dqtor(tmp->data, tmp->data_size, ap);
		va_end(cpy);
		free(tmp);
	}
	va_end(ap);
	free(*adeq);
	*adeq = NULL;
}
