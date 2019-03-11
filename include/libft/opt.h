/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:08 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/11 23:15:04 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPT_H
# define OPT_H

# include "../dependencies.h"

# define UNKNOWN_OPTION (-1)
# define NO_OPT (-2)

enum			e_opt {
	FT_OPT_END = 0,
	FT_OPT_BOOLEAN,
	FT_OPT_STRING,
	FT_OPT_INTEGER
};

typedef struct	s_opt {
	enum e_opt	type;
	const char	short_name;
	const char	*long_name;
	void		*value;
	const char	*help;
	int			flag;
}				t_opt;

extern int		ft_optparse(const t_opt opts[], int *index, int optc,
				char *optv[]);
extern int		ft_optusage(const t_opt opts[], char *name, char *usage,
				char *desc);

#endif
