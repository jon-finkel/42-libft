/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 19:35:48 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/26 21:50:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOL_H
# define LOL_H

# include "./dependencies.h"

# ifndef BYEZ
#  define BYEZ return
# endif

# ifndef GIMME
#  define GIMME(x) return (x)
# endif

# ifndef KEEPATITBRA
#  define KEEPATITBRA continue
# endif

# ifndef KTHXBYE
#  define KTHXBYE return (0)
# endif

# ifndef IMOUTTAYR
#  define IMOUTTAYR return
# endif

# ifndef ONOES
#  define ONOES return (-1)
# endif

# ifndef ZOMG
#  define ZOMG return (NULL)
# endif

# ifndef FAILZ
#  define FAILZ(x, y) ({if(!(x)) return(y);})
# endif

# ifndef EPICFAILZ
#  define EPICFAILZ(x, y) ({if((x) < 0) return(y);})
# endif

# ifndef IMOUTTAHERE
#  define IMOUTTAHERE(x) ({if(!(x)) exit(EXIT_FAILURE);})
# endif

#endif
