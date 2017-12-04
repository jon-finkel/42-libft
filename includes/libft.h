/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 17:50:38 by nfinkel           #+#    #+#             */
/*   Updated: 2017/12/04 19:48:40 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <inttypes.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define ABS(x) ({typeof(x) _x = (x);_x < 0 ? -_x : _x;})
# define MIN(a, b) ({typeof(a) _a = (a);typeof(b) _b = (b);_a > _b ? _b : _a;})
# define MAX(a, b) ({typeof(a) _a = (a);typeof(b) _b = (b);_a < _b ? _b : _a;})
# define PROTECT(x, y) ({if(!(x)) return(y);})
# define EXIT_PROTECT(x) ({if(!(x)) exit(EXIT_FAILURE);})

/*
** UTF-8 charset defines
*/
# define FOUR_BYTES_UNICODE(x) (x >= 0x10000 && x <= 0x10FFFF)
# define THREE_BYTES_UNICODE(x) (x >= 0x800 && x < 0x10000)
# define TWO_BYTES_UNICODE(x) (x >= 0x80 && x < 0x800)
# define THREE_OR_MORE_BYTES_UNICODE(x) (x >= 0x800 && x <= 0x10FFFF)
# define TWO_OR_MORE_BYTES_UNICODE(x) (x >= 0x80 && x <= 0x10FFFF)
# define FOUR_BYTES_UNICODE_HEAD(x) (x >> 18 | 0xF0)
# define THREE_BYTES_UNICODE_HEAD(x) (x >> 12 | 0xE0)
# define THREE_BYTES_UNICODE_BODY(x) ((x >> 12 & 0x3F) | 0x80)
# define TWO_BYTES_UNICODE_HEAD(x) (x >> 6 | 0xC0)
# define TWO_BYTES_UNICODE_BODY(x) ((x >> 6 & 0x3F) | 0x80)
# define UNICODE_TAIL(x) ((x & 0x3F) | 0x80)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**##############################
**##   String  manipulation   ##
**##############################
*/
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
size_t				ft_intlen(intmax_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(const char *s1, const char *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *s1, const char *s2, size_t n);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strnstr(const char *big, const char *little, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *const s);
char				*ft_strrevcpy(const char *const s);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);

/*
**##############################
**##   Memory  manipulation   ##
**##############################
*/
void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);

/*
**##############################
**## Linked list manipulation ##
**##############################
*/
void				ft_lstadd(t_list **alst, t_list *newlink);
void				ft_lstclear(void *data, size_t size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstgetnode(t_list *list, size_t n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
size_t				ft_lstsize(t_list *list);

/*
**##############################
**##       Input output       ##
**##############################
*/
int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_snprintf(char *str, size_t size, const char *format,
					...);
int					ft_sprintf(char *str, const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list ap);
int					ft_vprintf(const char *format, va_list ap);
int					ft_vsprintf(char *str, const char *format, va_list ap);
int					ft_vsnprintf(char *str, size_t size, const char *format,
					va_list ap);

void				ft_kill(const char *s, const int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *s);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putuchar(int c);
void				ft_putuchar_fd(int c, const int fd);

int					get_next_line(const int fd, char **line);

/*
**##############################
**##  Character manipulation  ##
**##############################
*/
int					ft_invert(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
