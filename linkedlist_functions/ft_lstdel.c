/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 21:50:04 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/20 09:21:15 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

void			ft_lstldtor(t_list **alst, t_ldtor ldtor, ...)
{
	t_list		*tmp;
	va_list		ap;

	va_start(ap, ldtor);
	tmp = *alst;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstdelone(&(*alst), ldtor, ap);
		*alst = tmp;
	}
	va_end(ap);
	alst = NULL;
}
