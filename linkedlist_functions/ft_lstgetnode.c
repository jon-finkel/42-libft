/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:32:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:20:43 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

const t_list			*ft_lstgetnode(const t_list *list, size_t n)
{
	++n;
	if (n > ft_lstsize(list))
		ZOMG;
	while (--n > 0)
		list = list->next;
	GIMME(list);
}
