/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 20:27:54 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/13 22:25:48 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dependencies.h"

int			ft_pgcd(int a, int b)
{
	int		pgcd;

	pgcd = MIN(a, b) + 1;
	while (--pgcd)
		if (!(a % pgcd) && !(b % pgcd))
			NOMOAR;
	GIMME(pgcd);
}
