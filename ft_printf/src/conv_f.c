/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:51 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:51 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

double		get_va_arg_f(t_lst *lst, va_list ap)
{
	if (lst->flg.upperl)
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}

void		raise_deci(t_lst *lst, char **str, long double nb)
{
	char	*tmp;
	char	*buff;

	tmp = ft_itoa(nb);
	if ((int)ft_strlen(tmp) > lst->flg.prc)
	{
		ft_strcat(*str, tmp);
		ft_strdel(&tmp);
		return ;
	}
	buff = ft_strnew(lst->flg.prc);
	ft_strcat(buff, tmp);
	ft_strdel(&tmp);
	ft_add_char_front('0', &buff, lst->flg.prc, ft_strlen(tmp));
	ft_strcat(*str, buff);
	ft_strdel(&buff);
}

int			notanumber(long double nb)
{
	if (nb != nb)
	{
		ft_putstr("0.000000");
		return (8);
	}
	return (0);
}

int			more_f(t_lst *lst, char **str, signed long int flt[2], int syb[2])
{
	int		len;

	ft_strcat(*str, ".");
	if (flt[1] == 0 && lst->flg.prc == 0)
		ft_strcat(*str, "000000");
	else
		raise_deci(lst, str, flt[1]);
	ft_add_char(lst, str);
	ft_add_symbole(lst, str, syb);
	len = ft_strlen(*str);
	ft_putstr(*str);
	ft_strdel(str);
	return (len);
}

int			conv_f(t_lst *lst, va_list ap)
{
	char			*str;
	char			*tmp;
	long double		nb;
	signed long int flt[2];
	int				syb[2];

	nb = get_va_arg_f(lst, ap);
	str = alloc_str(lst, nb, &flt);
	if (lst->flg.wth > 0 && lst->flg.mns)
		lst->flg.wth = -lst->flg.wth;
	syb[0] = (nb < 0 ? 1 : ft_remove_char('-', &str));
	syb[1] = ft_remove_char('+', &str);
	syb[1] = (lst->flg.pls ? 1 : syb[1]);
	if (lst->flg.wth > 0)
		lst->flg.wth = lst->flg.wth - (syb[1] ? syb[1] : syb[0]);
	else
		lst->flg.wth = lst->flg.wth + (syb[1] ? syb[1] : syb[0]);
	tmp = ft_itoa(flt[0]);
	ft_strcat(str, tmp);
	ft_strdel(&tmp);
	if (notanumber(nb) > 0)
		return (8);
	return (more_f(lst, &str, flt, syb));
}
