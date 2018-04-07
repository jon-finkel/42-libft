/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:39:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/06 16:42:23 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HDL_H
# define HDL_H

# include <errno.h>
# include "dependencies.h"

# define ERRMAX (7)

typedef enum			e_err
{
	ERR_NOMEM,
	ERR_OPEN,
	ERR_CLOSE,
	ERR_READ,
	ERR_MLX,
	ERR_MLXWIN,
	ERR_MLXIMG
}						t_err;

typedef void			(*t_dqtor)(void *, size_t, va_list ap);
typedef void			(*t_ldtor)(void *, size_t, va_list ap);
typedef void			(*t_vdtor)(void *, va_list ap);
typedef void			(*t_vdstor)(void *, va_list ap);

_Noreturn void			ft_errhdl(void **aptr, size_t size, int errcode);

#endif
