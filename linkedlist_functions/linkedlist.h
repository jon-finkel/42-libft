/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:37 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/11 14:21:08 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

# include "../includes/dependencies.h"

typedef struct			s_list
{
	size_t				data_size;
	void				*data;
	struct s_list		*next;
}						t_list;

extern void				ft_lstadd(t_list **alst, t_list *newlink);
extern void				ft_lstappend(t_list *list, t_list *newlink);
extern void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
extern void				ft_lstdelone(t_list **alst, void (*dl)(void *, size_t));
extern void				ft_lstfree(void *data, size_t size);
extern const t_list		*ft_lstgetnode(const t_list *list, size_t n);
extern void				ft_lstinsert(t_list **alst, t_list *newlink,
						int (*del)(void *, void *));
extern void				ft_lstiter(t_list *lst, void (*f)(t_list *));
extern t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *));
extern t_list			*ft_lstnew(const void *data, size_t data_size);
extern size_t			ft_lstsize(const t_list *list);
extern void				ft_lstsnipe(t_list **alst, t_list *target,
						void (*del)(void *, size_t));

#endif
