/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctime_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:23:24 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/03 16:41:09 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTIME_PRIVATE_H
# define FT_CTIME_PRIVATE_H

# include "../includes/libft.h"

#define LEAP_YEAR_SECONDS 31622400
#define YEAR_SECONDS 31536000

struct		s_time
{
	int16_t	year_n;
	char	*year;
	int8_t	month;
	int8_t	day_n;
	char	*day;
	char	*hour;
	char	*minutes;
	char	*seconds;
};

#endif
