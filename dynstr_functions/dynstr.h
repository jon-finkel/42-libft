/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 22:39:36 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/24 23:01:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DYNSTR_H
# define DYNSTR_H

# include "../includes/handlers.h"

# define DSTR_MIN_LIMIT 4

typedef struct		s_dstr
{
	char			*buff;
	size_t			capacity;
	size_t			len;
}					t_dstr;

extern size_t		ft_dstralloc(t_dstr *dstr, size_t size);
extern char			*ft_dstrbegin(t_dstr *dstr);
extern void			ft_dstrclear(t_dstr *dstr, t_vdstor vdstor, ...);
extern void			ft_dstrdel(t_dstr *dstr, t_vdstor vdstor, ...);
extern char			*ft_dstrend(t_dstr *dstr);
extern size_t		ft_dstrgrow(t_dstr *dstr, size_t size);
extern char			*ft_dstrnpush(t_dstr *dstr, size_t size);
extern char			*ft_dstrpush(t_dstr *dstr);

#endif
