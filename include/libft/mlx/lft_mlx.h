/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lft_mlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:58:00 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/05 13:52:26 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MLX_H
# define LFT_MLX_H

# include "libft/mat.h"
# include "libft/vary.h"
# include "libft/mlx/keys.h"

# define _MLX_ID mlx->mlx
# define _MLX_IMG mlx->img[mlx->cur_img]
# define _MLX_IMG_ID mlx->img[mlx->cur_img]->img
# define _MLX_WIN_ID mlx->win[mlx->cur_win]

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
	uint16_t			cur_win;
	void				*mlx;
	void				**win;
}						t_mlx;

extern t_mlx_img		*ftx_blurimg(t_mlx_img *img);
extern t_mlx_img		*ftx_buffpixel(t_mlx_img *img, const int x, const int y,
						int color);
extern t_mlx_img		*ftx_clearimg(t_mlx_img *img);
extern t_mlx_img		*ftx_clipimg(t_mlx_img *img, const t_point begin,
						const t_point end);
extern t_mlx_img		*ftx_drawline(t_mlx_img *img, const t_vec4 v1,
						const t_vec4 v2, int color);
extern t_mlx_img		*ftx_hline(t_mlx_img *img, const t_vec4 v1,
						const t_vec4 v2, int color);
extern t_mlx_img		*ftx_imgctor(t_mlx *mlx, int width, int height);
extern void				ftx_imgdtor(void *data, va_list ap);
extern t_mlx			*ftx_init(t_mlx *mlx);
extern void				ftx_mlxdtor(t_mlx *mlx);
extern t_mlx_img		*ftx_setimg(t_mlx *mlx, uint16_t n);
extern void				*ftx_setwin(t_mlx *mlx, uint16_t n);
extern t_mlx_img		*ftx_vline(t_mlx_img *img, const t_vec4 v1,
						const t_vec4 v2, int color);
extern void				ftx_winctor(t_mlx *mlx, int size_x, int size_y,
						char *title);
extern void				ftx_windtor(void *data, va_list ap);

/*
** MLX functions
*/
extern int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);
extern int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);
extern char				*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
						int *size_line, int *endian);
extern void				*mlx_new_image(void *mlx_ptr, int width, int height);
extern void				*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
						char *title);
extern void				*mlx_init(void);

#endif
