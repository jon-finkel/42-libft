/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsnipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 22:44:30 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/20 09:23:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

void			ft_lstsnipe(t_list **alst, t_list *target, t_ldtor ldtor, ...)
{
	t_list		*list;
	va_list		ap;

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
