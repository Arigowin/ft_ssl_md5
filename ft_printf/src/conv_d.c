/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:07 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:41:13 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

long long int	get_va_arg_d(t_lst *lst, va_list ap)
{
	if (lst->flg.hh)
		return ((char)va_arg(ap, int));
	if (lst->flg.h)
		return ((short int)va_arg(ap, int));
	if (lst->flg.ll)
		return (va_arg(ap, long long int));
	if (lst->flg.l)
		return (va_arg(ap, long int));
	return (va_arg(ap, int));
}

char			*alloc_buff(t_lst *lst, long long int nb)
{
	char	*buff;
	char	*tmp;
	int		len;

	if (lst->flg.wth < 0)
		lst->flg.wth = -lst->flg.wth;
	tmp = ft_lltoa(nb);
	len = ft_strlen(tmp);
	if (lst->flg.wth + lst->flg.prc > len)
		buff = ft_strnew(lst->flg.wth + lst->flg.prc);
	else
		buff = ft_strnew(len);
	ft_memcpy(buff, tmp, len);
	ft_strdel(&tmp);
	return (buff);
}

void			more_d(t_lst *lst, char **str, long long int nb)
{
	if (!lst->flg.prc && lst->flg.point && !nb && lst->flg.wth)
		ft_memset(*str, ' ', ft_strlen(*str));
	else if (!lst->flg.prc && lst->flg.point && !nb)
		ft_bzero(*str, ft_strlen(*str));
}

int				conv_d(t_lst *lst, va_list ap)
{
	char			*str;
	long long int	nb;
	int				len;
	int				syb[2];

	nb = get_va_arg_d(lst, ap);
	str = alloc_buff(lst, nb);
	if (lst->flg.wth > 0 && lst->flg.mns)
		lst->flg.wth = -lst->flg.wth;
	syb[0] = ft_remove_char('-', &str);
	syb[1] = (lst->flg.pls ? 1 : ft_remove_char('+', &str));
	if (lst->flg.prc != 0)
		lst->flg.prc = (lst->flg.prc < (int)ft_strlen(str) ? -1 : lst->flg.prc);
	if (lst->flg.wth > 0)
		lst->flg.wth = lst->flg.wth - (syb[1] ? syb[1] : syb[0]);
	else
		lst->flg.wth = lst->flg.wth + (syb[1] ? syb[1] : syb[0]);
	ft_add_char(lst, &str);
	ft_add_symbole(lst, &str, syb);
	more_d(lst, &str, nb);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
