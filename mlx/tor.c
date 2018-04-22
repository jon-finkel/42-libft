/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:47:12 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 16:24:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/mlxh.h"

static t_vary	g_mlx_img_vary_null = {NULL, 0, 0, sizeof(t_mlx_img *)};
static t_vary	g_mlx_win_vary_null = {NULL, 0, 0, sizeof(void *)};
static t_vary	*g_mlx_img_vary = &g_mlx_img_vary_null;
static t_vary	*g_mlx_win_vary = &g_mlx_win_vary_null;

inline t_mlx_img	*ftx_imgctor(t_mlx *mlx, int width, int height)
{
	t_mlx_img	*img;

	img = (t_mlx_img *)ft_memalloc(sizeof(t_mlx_img));
	if (!(img->img = mlx_new_image(mlx->mlx, width, height)))
		ft_errhdl(NULL, 0, 0, ERR_MLXIMG);
	img->height = height;
	img->width = width;
	img->addr = mlx_get_data_addr(img->img, &img->bppx, &img->sl, &img->endian);
	*(t_mlx_img **)ft_varypush(g_mlx_img_vary) = img;
	mlx->img = g_mlx_img_vary->buff;
	GIMME(img);
}

inline void			ftx_imgdtor(void *data, va_list ap)
{
	t_mlx	*mlx;

	mlx = va_arg(ap, t_mlx *);
	mlx_destroy_image(mlx->mlx, (*(t_mlx_img **)(data))->img);
	ft_memdtor((void **)&*(t_mlx_img **)data);
}

inline void			ftx_mlxdtor(t_mlx *mlx)
{
	ft_varydtor(&g_mlx_img_vary, ftx_imgdtor, mlx);
	ft_varydtor(&g_mlx_win_vary, ftx_windtor, mlx);
}

inline void			ftx_winctor(t_mlx *mlx, int size_x, int size_y, char *title)
{
	void	*win;

	if (!(win = mlx_new_window(_MLX_ID, size_x, size_y, title)))
		ft_errhdl(NULL, 0, 0, ERR_MLXWIN);
	*(void **)ft_varypush(g_mlx_win_vary) = win;
	mlx->win = g_mlx_win_vary->buff;
}

inline void			ftx_windtor(void *data, va_list ap)
{
	t_mlx	*mlx;

	mlx = va_arg(ap, t_mlx *);
	mlx_destroy_window(mlx->mlx, *(void **)(data));
}
