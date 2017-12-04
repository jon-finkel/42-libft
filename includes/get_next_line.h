/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:23:30 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/04 19:50:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define ERROR -1
# define BUFF_SIZE 4096

struct				s_file
{
	char			*file;
	char			*begin_file;
	int				fd;
	struct s_file	*next;
};

#endif
