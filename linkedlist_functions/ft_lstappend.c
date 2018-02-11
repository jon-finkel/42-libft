/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:31:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/11 10:14:56 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

inline void			ft_lstappend(t_list *list, t_list *newlink)
{
	while (list->next)
		list = list->next;
	list->next = newlink;
}
