/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:32:34 by nfinkel           #+#    #+#             */
/*   Updated: 2017/09/18 16:41:44 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstgetnode(t_list *list, size_t n)
{
	++n;
	if (n > ft_lstsize(list))
		return (NULL);
	while (--n > 0)
		list = list->next;
	return (list);
}
