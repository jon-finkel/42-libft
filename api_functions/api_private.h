/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_private.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:46:03 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 16:18:20 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_PRIVATE_H
# define API_PRIVATE_H

# include "../includes/dependencies.h"

# define LEAP_YEAR_SECONDS 31622400
# define YEAR_SECONDS 31536000

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

char		*ft_ctime(const time_t *clock);
char		*ft_getenv(const char *name);
int			ft_putenv(char *string);
int			ft_setenv(const char *name, const char *value, int overwrite);
int			ft_unsetenv(const char *name);

#endif
