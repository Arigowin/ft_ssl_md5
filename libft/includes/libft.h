/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:02:00 by dolewski          #+#    #+#             */
/*   Updated: 2016/03/07 11:25:53 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BLACK    "\033[0;30m"
# define RED      "\033[0;31m"
# define GREEN    "\033[0;32m"
# define YELLOW   "\033[0;33m"
# define BLUE     "\033[0;34m"
# define PURPLE   "\033[0;35m"
# define CYAN     "\033[0;36m"
# define GREY     "\033[0;37m"

# define DEFAULT_COLOR "\033[0m"

# include <string.h>

/*
** mem
*/

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

/*
** string
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strproperjoin(char **s1, char **s2);

/*
** is
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** put
*/

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(const char *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_color(char *color, char c);
void				ft_putstr_color(char *color, char *s);
void				ft_putnbr_color(char *color, int n);
void				ft_putchar_color_fd(int fd, char *color, char c);
void				ft_putstr_color_fd(int fd, char *color, char *s);
void				ft_putnbrendl(int n);

/*
** lst
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alist, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list*(*f)(t_list *elem));
void				ft_lstpushback(t_list **alst, t_list *new);
int					ft_lstcount(t_list *lst);

/*
** other
*/

t_list				*ft_splittolst(const char *s, char c);
void				ft_free_tbl_s(char **tbl);
char				*ft_itoa_base(int n, int base);
char				*ft_itoa(int n);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_copyt2d(char ***t1, char **t2, size_t size, size_t ns);
void				ft_freet2d(char ***t, int len);
char				*str_toupper(char *str);

#endif
