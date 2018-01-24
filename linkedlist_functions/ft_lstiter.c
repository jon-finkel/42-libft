/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 22:38:48 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:03:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist_private.h"

inline void			ft_lstiter(t_list *lst, void (*f)(t_list *))
{
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
}
