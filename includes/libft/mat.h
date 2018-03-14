/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:46 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/14 21:16:27 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# include "dependencies.h"

extern size_t			ft_nextpower2(size_t nb);
extern int				ft_pgcd(int a, int b);
extern int32_t			ft_32npow(const int32_t nb, int power);
extern int64_t			ft_64npow(const int64_t nb, int power);

#endif