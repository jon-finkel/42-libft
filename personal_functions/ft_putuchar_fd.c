/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:13:52 by nfinkel           #+#    #+#             */
/*   Updated: 2017/11/15 10:59:02 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putuchar_fd(int c, const int fd)
{
	if (ft_isascii(c))
		ft_putchar_fd((char)c, fd);
	if (FOUR_BYTES_UNICODE(c))
	{
		ft_putchar_fd((char)FOUR_BYTES_UNICODE_HEAD(c), fd);
		ft_putchar_fd((char)THREE_BYTES_UNICODE_BODY(c), fd);
	}
	if (THREE_BYTES_UNICODE(c))
		ft_putchar_fd((char)THREE_BYTES_UNICODE_HEAD(c), fd);
	if (THREE_OR_MORE_BYTES_UNICODE(c))
		ft_putchar_fd((char)TWO_BYTES_UNICODE_BODY(c), fd);
	if (TWO_BYTES_UNICODE(c))
		ft_putchar_fd((char)TWO_BYTES_UNICODE_HEAD(c), fd);
	if (TWO_OR_MORE_BYTES_UNICODE(c))
		ft_putchar_fd((char)UNICODE_TAIL(c), fd);
}
