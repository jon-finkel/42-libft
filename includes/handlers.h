/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:39:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/20 08:16:36 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "../includes/dependencies.h"
# include <errno.h>

typedef void		(*t_dqtor)(void *, size_t, ...);
typedef void		(*t_ldtor)(void *, size_t, ...);
typedef void		(*t_vdtor)(void *, ...);

extern void			ft_errhdl(void **aptr, size_t size, int errcode, ...);

#endif
