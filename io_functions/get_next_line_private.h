/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:23:30 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/24 11:13:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PRIVATE_H
# define GET_NEXT_LINE_PRIVATE_H

# include "../includes/libft.h"

# define LIST_CONTENT ((t_data *)(list->content))

# define BUFF_SIZE 4095

typedef struct	s_data
{
	char		*begin;
	char		*str;
	int			fd;
}				t_data;

#endif
