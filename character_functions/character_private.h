/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:54:16 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 14:56:05 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_PRIVATE_H
# define CHARACTER_PRIVATE_H

# include "../includes/dependencies.h"

extern int			ft_isalpha(int c);
extern int			ft_isalnum(int c);
extern int			ft_isascii(int c);
extern int			ft_isdigit(int c);
extern int			ft_islower(int c);
extern int			ft_isprint(int c);
extern int			ft_isupper(int c);
extern int			ft_tolower(int c);
extern int			ft_toupper(int c);

#endif
