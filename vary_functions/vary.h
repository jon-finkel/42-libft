/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vary.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 08:58:27 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/25 09:09:14 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARY_H
# define VARY_H

# include "../includes/handlers.h"

# define VARY_MIN_SIZE 4

typedef struct		s_vary
{
	void			*buff;
	size_t			capacity;
	size_t			len;
	size_t			data_size;
}					t_vary;

extern size_t		ft_varyalloc(t_vary *vary, size_t size);
extern void			*ft_varybegin(t_vary *vary);
extern void			ft_varyclr(t_vary *vary, t_vdtor vdtor, ...);
extern void			ft_varydel(t_vary **avar, t_vdtor vdtor, ...);
extern void			*ft_varyend(t_vary *vary);
extern size_t		ft_varygrow(t_vary *vary, size_t size);
extern void			*ft_varynpush(t_vary *vary, size_t size);
extern void			*ft_varypush(t_vary *vary);

#endif
