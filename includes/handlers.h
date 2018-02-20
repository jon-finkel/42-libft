/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:39:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/20 09:17:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "../includes/dependencies.h"
# include <errno.h>

typedef void		(*t_dqtor)(void *, size_t, va_list ap);
typedef void		(*t_ldtor)(void *, size_t, va_list ap);
typedef void		(*t_vdtor)(void *, va_list ap);

extern void			ft_errhdl(void **aptr, size_t size, int errcode);

#endif
