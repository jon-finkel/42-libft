/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:04:45 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/04 19:48:23 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/mem.h"
#include "libft/mlx.h"

static t_vary		g_mlx_img_vary_null = {NULL, 0, 0, sizeof(t_mlx_img *)};
static t_vary		g_mlx_win_vary_null = {NULL, 0, 0, sizeof(void *)};
static t_vary		*g_mlx_img_vary = &g_mlx_img_vary_null;
static t_vary		*g_mlx_win_vary = &g_mlx_win_vary_null;

void				ftx_init(t_mlx *mlx)
{
	ft_memset(mlx, '\0', sizeof(t_mlx));
	if (!(_MLX_ID = mlx_init()))
		ft_errhdl(NULL, 0, ERR_MLX);
}

void				ftx_imgdtor(void *data, va_list ap)
{
	t_mlx		*mlx;

	mlx = va_arg(ap, t_mlx *);
	mlx_destroy_image(mlx->mlx, (*(t_mlx_img **)(data))->img);
	ft_memdel((void **)&*(t_mlx_img **)data);
}

void				ftx_windtor(void *data, va_list ap)
{
	t_mlx		*mlx;

	mlx = va_arg(ap, t_mlx *);
	mlx_destroy_window(mlx->mlx, *(void **)(data));
	ft_memdel((void **)data);
}

void				ftx_mlxdtor(t_mlx *mlx)
{
	ft_varydel(&g_mlx_img_vary, ftx_imgdtor, mlx);
	ft_varydel(&g_mlx_win_vary, ftx_windtor, mlx);
	ft_memdel((void **)&mlx->mlx);
	ft_memdel((void **)&mlx);
}

void				ftx_winctor(t_mlx *mlx, int size_x, int size_y, char *title)
{
	void		*win;

	if (!(win = mlx_new_window(_MLX_ID, size_x, size_y, title)))
		ft_errhdl(NULL, 0, ERR_MLXWIN);
	*(void **)ft_varypush(g_mlx_win_vary) = win;
	mlx->win = g_mlx_win_vary->buff;
}

void				*ftx_setwin(t_mlx *mlx, uint16_t n)
{
	mlx->cur_win = n;
	GIMME(_MLX_WIN_ID);
}

t_mlx_img			*ftx_imgctor(t_mlx *mlx, int width, int height)
{
	t_mlx_img		*img;

	img = (t_mlx_img *)ft_memalloc(sizeof(t_mlx_img));
	if (!(img->img = mlx_new_image(mlx->mlx, width, height)))
		ft_errhdl(NULL, 0, ERR_MLXIMG);
	img->height = height;
	img->width = width;
	img->addr = mlx_get_data_addr(img->img, &img->bppx, &img->sl, &img->endian);
	*(t_mlx_img **)ft_varypush(g_mlx_img_vary) = img;
	mlx->img = g_mlx_img_vary->buff;
	GIMME(img);
}

t_mlx_img			*ftx_blurrimg(t_mlx_img *img)
{
	int		x;
	int		y;

	y = -1;
	while (++y < img->height && (x = -1))
		while (++x < img->width)
			ftx_buffpixel(img, x, y, 0xA0000000);
	GIMME(img);
}

t_mlx_img			*ftx_clearimg(t_mlx_img *img)
{
	int		x;
	int		y;

	y = -1;
	while (++y < img->height && (x = -1))
		while (++x < img->width)
			ftx_buffpixel(img, x, y, 0x00000000);
	GIMME(img);
}

t_mlx_img			*ftx_setimg(t_mlx *mlx, uint16_t n)
{
	mlx->cur_img = n;
	GIMME(_MLX_IMG);
}
