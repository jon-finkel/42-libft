/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:46 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/11 20:31:40 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT_H
# define MAT_H

# include "../includes/dependencies.h"

extern size_t			ft_nextpower2(size_t nb);
extern int				ft_pgcd(int a, int b);
extern void				ft_polynomial(const double *p, const int degree);

#endif
