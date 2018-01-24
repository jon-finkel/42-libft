/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 22:33:22 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:01:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist_private.h"

inline void			ft_lstadd(t_list **alst, t_list *newlink)
{
	newlink->next = *(alst);
	*alst = newlink;
}
