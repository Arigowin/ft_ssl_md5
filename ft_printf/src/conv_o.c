/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:08 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:08 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

long long int	get_va_arg_o(t_lst *lst, va_list ap)
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

int				search_o(char *str, char *nb)
{
	char	*tmp;

	tmp = ft_strstr(str, nb);
	if (ft_strcmp(str, tmp) == 0 || (tmp - 1)[0] != '0')
		return (1);
	return (0);
}

void			more_o(t_lst *lst, char **str, unsigned int nb)
{
	if (!lst->flg.prc && lst->flg.point && !nb && lst->flg.wth)
		ft_memset(*str, ' ', ft_strlen(*str));
	else if (!lst->flg.prc && lst->flg.point && !nb && !lst->flg.sharp)
		ft_bzero(*str, ft_strlen(*str));
}

int				conv_o(t_lst *lst, va_list ap)
{
	char						*str;
	char						*buff;
	int							len;
	unsigned long long int		nb;
	int							w;

	len = 0;
	nb = get_va_arg_o(lst, ap);
	w = (lst->flg.wth < 0 ? -lst->flg.wth : lst->flg.wth);
	str = (w + lst->flg.prc && w + lst->flg.prc >= 30 ?
			ft_strnew(w + lst->flg.prc) : ft_strnew(30));
	ft_prntnum(nb, 8, ' ', str);
	buff = ft_strdup(str);
	lst->flg.prc = (lst->flg.prc < (int)ft_strlen(str) ? 0 : lst->flg.prc);
	ft_add_char(lst, &str);
	if (lst->flg.sharp && nb > 0 && search_o(str, buff))
		add_o(lst, &str, buff);
	ft_strdel(&buff);
	more_o(lst, &str, nb);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
