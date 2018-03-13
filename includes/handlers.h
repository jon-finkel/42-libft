/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:39:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 00:39:42 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "../includes/dependencies.h"
# include <errno.h>

# define ERR_MAX (2)

typedef enum		e_err
{
	ERR_NOMEM,
	ERR_FD
}					t_err;

typedef void		(*t_dqtor)(void *, size_t, va_list ap);
typedef void		(*t_ldtor)(void *, size_t, va_list ap);
typedef void		(*t_vdtor)(void *, va_list ap);
typedef void		(*t_vdstor)(void *, va_list ap);

extern void			ft_errhdl(void **aptr, size_t size, int errcode);

#endif
