/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrewrite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:34:57 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/12 21:49:14 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Find the string needle in the string haystack, and replace the needle part
** with filler. If needle isn't present in haystack, ft_strrewrite doesn't do
** anything. If filler is NULL, needle will effectively be erased from haystack.
** ft_strrewrite does not check that the size of the haystack is large enough
** to hold the rewritten string, it is up to the user to do so.
*/

int			ft_strrewrite(char *restrict haystack, const char *restrict needle,
			const char *restrict filler)
{
	char		*copy;
	int			k;
	size_t		haystack_len;
	size_t		lit_len;

	lit_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	FAILZ(needle = ft_strstr(haystack, needle), 0);
	FAILZ(copy = ft_strdup(needle + lit_len), -1);
	haystack += haystack_len - ft_strlen(needle);
	while (*filler)
		*haystack++ = *filler++;
	k = -1;
	while (copy[++k])
		*haystack++ = copy[k];
	*haystack = '\0';
	free(copy);
	KTHXBYE;
}
