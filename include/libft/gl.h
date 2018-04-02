/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 20:43:54 by nfinkel           #+#    #+#             */
/*   Updated: 2018/04/02 20:53:25 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GL_H
# define GL_H

# include "libft/vary.h"

typedef struct		s_shader
{
	char			*shader;
	const char		*path;
	t_dstr			*dstr;
}					t_shader;

extern t_shader		*ftgl_compile_shader(const char *path);

#endif
