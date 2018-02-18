/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:13:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/18 08:48:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_dlstadd(t_dlist **adlst, t_dlist *newlink)
{
	if (*adlst)
		(*adlst)->prev = newlink;
	newlink->next = *adlst;
	*adlst = newlink;
}
