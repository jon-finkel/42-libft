/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poly.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 20:29:13 by nfinkel           #+#    #+#             */
/*   Updated: 2018/03/11 20:32:34 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mat.h"
#include "../io/io.h"
#include <math.h>

static const char		*g_error[4] =
{
	"Can only solve polynomial equations up to and including 2nd degree.",
	"This equation has no solution.",
	"This equation is valid for any real number n.",
	"This equation is valid for any number n with n"
};

static void			zero_dis(const double *p)
{
	int		top;
	int		bot;
	int		neg;
	int		pgcd;

	ft_printf("The solution is:\n");
	top = (int)p[1];
	bot = (int)(2 * p[2]);
	neg = ((p[1] >= 0 && p[2] >= 0) || (p[1] < 0 && p[2] < 0) ? 1 : 0);
	if ((int)(p[1] / (2 * p[2])) != p[1] / (2 * p[2])
		&& (double)top == p[1] && (double)bot == 2 * p[2])
	{
		pgcd = ft_pgcd(top, bot);
		ft_printf("    x = %c%d/%d\n<=> ", (neg ? '-' : 0), ABS(top / pgcd),\
			ABS(bot / pgcd));
	}
	ft_printf("x = %f\n", INVERT(p[1] / (2 * p[2])));
}

static void			pos_dis(const double *p, const double dis)
{
	ft_printf("There are two solutions:\n");
	ft_printf("x = %f\n", INVERT((p[1] - sqrt(dis)) / (2 * p[2])));
	ft_printf("x = %f\n", INVERT((p[1] + sqrt(dis)) / (2 * p[2])));
}

void				ft_polynomial(const double *p, const int degree)
{
	double		dis;

	if (degree > 2 && ft_printf("%s\n", g_error[0]))
		BYEZ;
	ft_printf("Polynomial degree: %d\n", degree);
	if (p[0] && !degree)
		ft_printf("%s\n", g_error[1]);
	else if (!p[0] && !degree && MB_CUR_MAX == 1)
		ft_printf("%s\n", g_error[2]);
	else if (!p[0] && !degree)
		ft_printf("%s%C%C.\n", g_error[3], 0x2208, 0x211d);
	else if (!(dis = POW2(p[1]) - 4 * p[2] * p[0]))
		zero_dis(p);
	else if (dis > 0)
		pos_dis(p, dis);
	else if (dis < 0)
		ft_printf("%s\n", g_error[1]);
}
