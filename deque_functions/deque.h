/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 15:46:09 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/16 20:43:12 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_H
# define DEQUE_H

# include "../includes/handlers.h"

typedef struct		s_dlist
{
	size_t			data_size;
	void			*data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct		s_deque
{
	t_dlist			*head;
	t_dlist			*tail;
}					t_deque;

extern void			ft_deqadd(t_deque *deque, t_dlist *newlink);
extern void			ft_deqappend(t_deque *deque, t_dlist *newlink);
extern void			ft_deqeject(t_deque *deque, t_dqtor dqtor);
extern void			ft_deqpop(t_deque *deque, t_dqtor dqtor);
extern void			ft_dlstadd(t_dlist **adlst, t_dlist *newlink);
extern void			ft_dlstappend(t_dlist *dlist, t_dlist *newlink);
extern t_dlist		*ft_dlstnew(const void *content, size_t content_size);

#endif
