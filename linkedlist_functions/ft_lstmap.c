/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 22:42:05 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:21:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list		*begin;
	t_list		*new;
	t_list		*tmp;

	tmp = f(lst);
	new = ft_lstnew(tmp->data, tmp->data_size);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		new->next = ft_lstnew(tmp->data, tmp->data_size);
		lst = lst->next;
		new = new->next;
	}
	GIMME(begin);
}
