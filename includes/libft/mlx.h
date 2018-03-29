/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 17:33:25 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/29 12:38:12 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LFT_MLX_H
# define LFT_MLX_H

# include "mlx_keys.h"
# include "libft/vary.h"

typedef struct		s_mlx_img
{
	char			*addr;
	int				bppx;
	int				endian;
	int				sl;
	int				height;
	int				width;
	void			*img;
}					t_mlx_img;

typedef struct		s_mlx
{
	t_mlx_img		**img;
	uint16_t		cur_img;
	void			*mlx;
	void			**win;
}					t_mlx;

extern t_vary		*g_mlx_win_vary;

extern void			ftx_init(t_mlx *mlx);
extern void			ftx_addwin(t_mlx *mlx, int size_x, int size_y,\
						char *title);
extern void			ftx_addimg(t_mlx *mlx, int width, int height);

extern char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,\
						int *size_line, int *endian);
extern void			*mlx_new_image(void *mlx_ptr, int width, int height);
extern void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,\
						char *title);
extern void			*mlx_init(void);

#endif
