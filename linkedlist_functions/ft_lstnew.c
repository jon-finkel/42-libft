/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 21:30:33 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:04:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist_private.h"
#include "../memory_functions/memory_private.h"

inline t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*list;

	FAILZ(list = (t_list *)malloc(sizeof(t_list)), NULL);
	if (!content)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		FAILZ(list->content = malloc(content_size), NULL);
		list->content = ft_memcpy(list->content, content, content_size);
		list->content_size = content_size;
	}
	list->next = NULL;
	GIMME(list);
}
