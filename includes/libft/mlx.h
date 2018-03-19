/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:25 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/19 15:49:03 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MLX_H
# define LFT_MLX_H

# include "mlx_keys.h"

typedef struct		s_mlx
{
	void			*mlx;
	void			**win;
}					t_mlx;

extern void			ft_mlxinit(t_mlx *mlx);
extern void			ft_mlxaddwin(t_mlx *mlx, int x, int y, char *title);

extern void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
					char *title);
extern void			*mlx_init(void);

#endif
