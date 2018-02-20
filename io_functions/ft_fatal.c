/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 16:46:11 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/20 18:36:00 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./io.h"

_Noreturn void			ft_fatal(const char *restrict s)
{
	ft_putstr_fd("fatal: ", STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
