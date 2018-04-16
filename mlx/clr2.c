/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:49:40 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/15 15:01:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mlxh.h"

t_mlx_img			*ftx_blurimg(t_mlx_img *img)
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
			ftx_buffpixel(img, x, y, 0xff000000);
	GIMME(img);
}

void				ftx_clearwin(t_mlx *mlx, const uint16_t index)
{
	uint16_t	prev;

	prev = mlx->cur_win;
	mlx_clear_window(_MLX_ID, ftx_setwin(mlx, index));
	mlx->cur_win = prev;
}

t_mlx_img			*ftx_clipimg(t_mlx_img *img, const t_p2 begin,
					const t_p2 end)
{
	int		x;
	int		y;

	y = begin.y - 1;
	while (++y <= end.y)
	{
		x = begin.x - 1;
		while (++x <= end.x)
			ftx_buffpixel(img, x, y, 0x00000000);
	}
	GIMME(img);
}
