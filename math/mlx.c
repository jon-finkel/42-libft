/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 15:04:45 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/28 20:59:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/hdl.h"
#include "libft/mem.h"
#include "libft/mlx.h"

static t_vary		g_mlx_win_vary_null = {NULL, 0, 0, sizeof(void *)};
t_vary				*g_mlx_win_vary = &g_mlx_win_vary_null;

void			ft_mlxinit(t_mlx *mlx)
{
	ft_memset(mlx, '\0', sizeof(t_mlx));
	if (!(mlx->mlx = mlx_init()))
		ft_errhdl(NULL, 0, ERR_MLX);
}

void			ft_mlxaddwin(t_mlx *mlx, int x, int y, char *title)
{
	void		*win;

	if (!(win = mlx_new_window(mlx->mlx, x, y, title)))
		ft_errhdl(NULL, 0, ERR_MLXWIN);
	*(void **)ft_varypush(g_mlx_win_vary) = win;
	mlx->win = g_mlx_win_vary->buff;
}
