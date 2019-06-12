/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:09 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:09 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

long long int		get_va_arg_x(t_lst *lst, va_list ap)
{
	if (lst->flg.hh)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (lst->flg.h)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (lst->flg.ll)
		return (va_arg(ap, unsigned long long int));
	if (lst->flg.l)
		return (va_arg(ap, unsigned long int));
	return (va_arg(ap, unsigned int));
}

void				more_add_x(char **str)
{
	char			*buff;
	int				i;

	i = 0;
	if ((*str)[ft_strlen(*str) - 1] == ' '
			&& (*str)[ft_strlen(*str) - 2] == ' ')
	{
		while ((*str)[i] && ft_strchr("0123456789abcdef", (*str)[i]))
			i++;
		while (i-- > 0)
			(*str)[i + 2] = (*str)[i];
		(*str)[0] = '0';
		(*str)[1] = 'x';
	}
	else
	{
		i = ((*str)[0] == ' ' && (*str)[1] != ' ' ? 1 : 2);
		buff = ft_strnew(ft_strlen(*str) + i);
		ft_memcpy(buff + i, *str, ft_strlen(*str));
		ft_strdel(str);
		buff[0] = '0';
		buff[1] = 'x';
		*str = buff;
	}
}

void				add_x(t_lst *lst, char **str, char *s2)
{
	int				i;

	i = 0;
	if ((((*str)[0] == ' ' && (*str)[1] == ' ') || (lst->flg.zero
					&& !lst->flg.point)) && ft_strlen(s2) != ft_strlen(*str))
	{
		while ((*str)[i] && !ft_strchr("0123456789abcdef", (*str)[i]))
			i++;
		(*str)[(i <= 2 ? 0 : i - 2)] = '0';
		(*str)[(i <= 1 ? 1 : i - 1)] = 'x';
	}
	else
		more_add_x(str);
}

int					more_x(t_lst *lst, char **str, unsigned long long int nb)
{
	if (!lst->flg.prc && lst->flg.point && !nb && lst->flg.wth)
		ft_memset(*str, ' ', ft_strlen(*str));
	else if (!lst->flg.prc && lst->flg.point && !nb)
		ft_bzero(*str, ft_strlen(*str));
	if (lst->type == LHEX)
		ft_putstr(*str);
	else
		ft_putupper(*str);
	return (ft_strlen(*str));
}

int					conv_x(t_lst *lst, va_list ap)
{
	char						*buff;
	char						*str;
	int							len;
	unsigned long long int		nb;
	int							w;

	len = 0;
	nb = get_va_arg_x(lst, ap);
	w = (lst->flg.wth < 0 ? -lst->flg.wth : lst->flg.wth);
	str = (w + lst->flg.prc && w + lst->flg.prc >= 30 ?
			ft_strnew(w + lst->flg.prc) : ft_strnew(30));
	ft_prntnum(nb, 16, ' ', str);
	buff = ft_strdup(str);
	lst->flg.prc = (lst->flg.prc < (int)ft_strlen(str) && nb
			&& lst->flg.prc ? -1 : lst->flg.prc);
	if (nb > 0 && lst->flg.sharp && ((int)ft_strlen(buff) + 2 >= w
				|| w - 2 <= lst->flg.prc))
		lst->flg.wth = 0;
	ft_add_char(lst, &str);
	if (lst->flg.sharp && nb > 0)
		add_x(lst, &str, buff);
	ft_strdel(&buff);
	len = more_x(lst, &str, nb);
	ft_strdel(&str);
	return (len);
}
