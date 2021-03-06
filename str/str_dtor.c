/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 16:34:57 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/22 17:27:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/str.h"

inline void	ft_strdtor(char **as)
{
	free(*as);
	*as = NULL;
}
