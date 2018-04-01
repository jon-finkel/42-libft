/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 12:18:44 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/02 01:18:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mem.h"
#include "libft/mlx.h"

t_mlx_img			*ftx_buffpixel(t_mlx_img *img, const int x, const int y,
					int color)
{
	char		*pos;

	if (x < 0 || x > img->width || y < 0 || y > img->height)
		GIMME(img);
	pos = img->addr + (y * img->sl) + (x * img->bppx / 8);
	if (img->endian)
		color = ft_bswap(color);
	ft_memmove(pos, &color, sizeof(color));
	GIMME(img);
}

t_mlx_img			*ftx_hline(t_mlx_img *img, const t_vec4 v1, const t_vec4 v2,
					int color)
{
	int		k;
	int		p;

	if (v1.y < 0 || v1.y >= img->height)
		GIMME(img);
	k = (int)MIN(v1.x, v2.x);
	p = (int)MAX(v1.x, v2.x);
	while (++k <= p)
		ftx_buffpixel(img, k, v1.y, color);
	GIMME(img);
}

t_mlx_img			*ftx_vline(t_mlx_img *img, const t_vec4 v1, const t_vec4 v2,
					int color)
{
	int		k;
	int		p;

	if (v1.x < 0 || v1.x >= img->width)
		GIMME(img);
	k = (int)MIN(v1.y, v2.y);
	p = (int)MAX(v1.y, v2.y);
	while (++k <= p)
		ftx_buffpixel(img, v1.x, k, color);
	GIMME(img);
}

t_mlx_img			*ftx_drawline(t_mlx_img *img, const t_vec4 v1,
					const t_vec4 v2, int color)
{
	int			k;
	double		x;
	double		y;

	if (v1.x == v2.x || v1.y == v2.y)
	{
		if (v1.x == v2.x && v1.y == v2.y)
			GIMME(ftx_buffpixel(img, v1.x, v1.y, color));
		else if (v1.x == v2.x)
			GIMME(ftx_vline(img, v1, v2, color));
		else
			GIMME(ftx_hline(img, v1, v2, color));
	}
	k = MAX(fabs(v1.x - v2.x), fabs(v1.y - v2.y) + 1);
	x = (v2.x - v1.x) / k;
	y = (v2.y - v1.y) / k;
	while (k--)
		ftx_buffpixel(img, (v1.x + x * k), (v1.y + y * k), color);
	GIMME(img);
}
