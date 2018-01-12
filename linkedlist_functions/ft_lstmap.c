/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 22:42:05 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/12 15:37:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list		*begin;
	t_list		*new;
	t_list		*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	FAILZ(new = ft_lstnew(tmp->content, tmp->content_size), NULL);
	begin = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		FAILZ(new->next = ft_lstnew(tmp->content, tmp->content_size), NULL);
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
