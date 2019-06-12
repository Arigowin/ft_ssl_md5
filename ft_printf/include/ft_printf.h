/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:12 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:41:54 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>

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
int					conv_s_body(t_lst *lst, char *buff);
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
void				ft_add_front_zero(t_lst *lst, char **str);

void				ft_add_char(t_lst *lst, char **str);
void				ft_add_symbole(t_lst *lst, char **str, int syb[2]);

void				ft_putupper(char const *s);

t_lst				*lst_add(t_lst **lst, t_type type, char *str);
void				lst_free(t_lst **lst);

size_t				ft_nbrlen(long long int nb);
void				ft_ptr_to_hex(const void *ptr, char (*res)[16]);
void				ft_print_n_char(char c, int n);
void				ft_add_n_char(char **str, char c, int n);
void				ft_add_char_front(char c, char **str, int nb, int len);
void				ft_add_char_back(char c, char **str, int nb, int start);
int					ft_remove_char(char c, char **str);
char				*ft_lltoa(long long int n);
void				ft_prntnum(unsigned long n, int b, char s, char *o);

#endif
