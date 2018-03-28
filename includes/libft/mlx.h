/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:25 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/28 21:47:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MLX_H
# define LFT_MLX_H

# include "mlx_keys.h"
# include "libft/vary.h"

typedef struct		s_mlx
{
	void			*mlx;
	void			**img;
	void			**win;
}					t_mlx;

extern t_vary		*g_mlx_win_vary;

extern void			ft_mlxinit(t_mlx *mlx);
extern void			ft_mlxaddwin(t_mlx *mlx, int x, int y, char *title);
extern void			ft_mlxaddimg(t_mlx *mlx, int x, int y);

extern void			*mlx_new_image(void *mlx_ptr, int width, int height);
extern void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
					char *title);
extern void			*mlx_init(void);

#endif
