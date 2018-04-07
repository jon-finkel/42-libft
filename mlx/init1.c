/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:04:45 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/07 11:47:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/mem.h"
#include "libft/mlxh.h"

t_mlx				*ftx_init(t_mlx *mlx)
{
	ft_memset(mlx, '\0', sizeof(t_mlx));
	if (!(_MLX_ID = mlx_init()))
		ft_errhdl(NULL, 0, 0, ERR_MLX);
	GIMME(mlx);
}

void				*ftx_setwin(t_mlx *mlx, uint16_t n)
{
	mlx->cur_win = n;
	GIMME(_MLX_WIN_ID);
}

t_mlx_img			*ftx_setimg(t_mlx *mlx, uint16_t n)
{
	mlx->cur_img = n;
	GIMME(_MLX_IMG);
}
