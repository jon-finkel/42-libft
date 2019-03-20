/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:15 by nfinkel           #+#    #+#             */
/*   Updated: 2019/03/20 12:57:17 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

# include "../dependencies.h"

extern bool	ft_isalpha(int c);
extern bool	ft_isalnum(int c);
extern bool	ft_isascii(int c);
extern bool	ft_isdigit(int c);
extern bool	ft_islower(int c);
extern bool	ft_isprint(int c);
extern bool	ft_isupper(int c);
extern int	ft_tolower(int c);
extern int	ft_toupper(int c);

#endif
