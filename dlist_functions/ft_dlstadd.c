/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:13:29 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/12 20:12:12 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./dlist.h"

void			ft_dlstadd(t_dlist **adlst, t_dlist *newlink)
{
	(*adlst)->prev = newlink;
	newlink->next = *adlst;
	newlink->prev = NULL;
	*adlst = newlink;
}
