/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:31:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:20:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

void			ft_lstappend(t_list *restrict list, t_list *restrict newlink)
{
	while (list->next)
		list = list->next;
	list->next = newlink;
}
