/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:25 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/31 12:15:40 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MLX_H
# define LFT_MLX_H

# include "mlx_keys.h"
# include "libft/mat.h"
# include "libft/vary.h"

typedef struct			s_mlx_img
{
	char				*addr;
	int					bppx;
	int					endian;
	int					sl;
	int					height;
	int					width;
	void				*img;
}						t_mlx_img;

typedef struct			s_mlx
{
	t_mlx_img			**img;
	uint16_t			cur_img;
	void				*mlx;
	void				**win;
}						t_mlx;

extern t_vary			*g_mlx_win_vary;

extern void				ftx_addwin(t_mlx *mlx, int size_x, int size_y,
						char *title);
extern void				ftx_addimg(t_mlx *mlx, int width, int height);
extern t_mlx_img		*ftx_buffpixel(t_mlx_img *img, const int x, const int y,
						int color);
extern t_mlx_img		*ftx_hline(t_mlx_img *img, const t_vec4 v1,
						const t_vec4 v2, int color);
extern void				ftx_init(t_mlx *mlx);
extern t_mlx_img		*ftx_vline(t_mlx_img *img, const t_vec4 v1,
						const t_vec4 v2, int color);

/*
** MLX functions
*/
extern char				*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
						int *size_line, int *endian);
extern void				*mlx_new_image(void *mlx_ptr, int width, int height);
extern void				*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
						char *title);
extern void				*mlx_init(void);

#endif
