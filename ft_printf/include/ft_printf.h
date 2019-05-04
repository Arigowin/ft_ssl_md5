/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:59 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:59 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include "../../libft/includes/libft.h"

typedef enum		e_type
{
	DFLT,
	OTHER,
	STR,
	INT,
	CHAR,
	PTR,
	OCT,
	UINT,
	LHEX,
	UHEX,
	FLT,
	PCT
}					t_type;

typedef struct		s_flags
{
	int				hh;
	int				h;
	int				ll;
	int				l;
	int				upperl;
	int				sharp;
	int				zero;
	int				mns;
	int				pls;
	int				spc;
	int				point;
	int				wth;
	int				prc;
}					t_flags;

typedef struct		s_lst
{
	double			flt;
	t_type			type;
	t_flags			flg;
	char			*str;
	struct s_lst	*next;
}					t_lst;

int					ft_printf(const char *format, ...);

void				parse(t_lst **lst, const char *format);
int					get_width(t_lst *lst);
int					get_precision(char *str);
int					print_all(t_lst *lst, va_list ap);
int					conversion_manager(t_lst *lst, va_list ap);
int					no_conv(t_lst *lst, va_list ap);
int					other_conv(t_lst *lst, va_list ap);
int					conv_pct(t_lst *lst, va_list ap);
int					conv_s(t_lst *lst, va_list ap);
int					conv_d(t_lst *lst, va_list ap);
int					conv_c(t_lst *lst, va_list ap);
int					conv_p(t_lst *lst, va_list ap);
int					conv_o(t_lst *lst, va_list ap);
void				add_o(t_lst *lst, char **str, char *nb);
int					conv_u(t_lst *lst, va_list ap);
int					conv_x(t_lst *lst, va_list ap);
int					conv_f(t_lst *lst, va_list ap);
char				*alloc_str(t_lst *lst, long double nb,
								signed long int (*flt)[2]);

void				ft_add_char(t_lst *lst, char **str);
void				ft_add_symbole(t_lst *lst, char **str, int syb[2]);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbrendl(int n);
void				ft_putupper(char const *s);

t_lst				*lst_add(t_lst **lst, t_type type, char *str);
void				lst_free(t_lst **lst);

size_t				ft_strlen(const char *s);
size_t				ft_nbrlen(int nb);
int					ft_strncount(char *str, char c);
char				*ft_itoa_base(int n, int base);
int					ft_atoi(const char *str);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_ptr_to_hex(const void *ptr, char (*res)[16]);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strstr(const char *s1, const char *s2);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcat(char *s1, const char *s2);
int					ft_isdigit(int c);
int					ft_toupper(int c);
void				ft_print_n_char(char c, int n);
void				ft_add_n_char(char **str, char c, int n);
void				ft_add_char_front(char c, char **str, int nb, int len);
void				ft_add_char_back(char c, char **str, int nb, int start);
int					ft_remove_char(char c, char **str);
void				ft_prntnum(unsigned long n, int b, char s, char *o);

#endif
