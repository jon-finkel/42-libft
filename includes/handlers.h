/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 19:39:06 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/13 07:45:16 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLERS_H
# define HANDLERS_H

# include "../includes/dependencies.h"

typedef void		(*t_ldtor)(void *, size_t, ...);
typedef void		(*t_vdtor)(void *, ...);

extern void			ft_errhdl(int errno);

#endif
