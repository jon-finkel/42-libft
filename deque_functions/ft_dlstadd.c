/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:13:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/16 20:25:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./deque.h"

void			ft_dlstadd(t_dlist **adlst, t_dlist *newlink)
{
	(*adlst)->prev = newlink;
	newlink->next = *adlst;
	*adlst = newlink;
}
