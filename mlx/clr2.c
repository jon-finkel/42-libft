/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clr2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 20:49:40 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/04 20:59:37 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/mlxh.h"

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
