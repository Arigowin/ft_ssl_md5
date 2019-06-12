/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:11 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:11 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void		remove_char(char **str, char *s2)
{
	char	*buff;
	size_t	i;
	size_t	j;

	buff = ft_strnew(ft_strlen(*str));
	i = 0;
	j = 0;
	while ((*str)[i])
	{
		if (!ft_strchr(s2, (*str)[i]))
			buff[j++] = (*str)[i];
		i++;
	}
	ft_strdel(str);
	*str = buff;
}

int			print_flag(char c)
{
	ft_putchar(c);
	return (1);
}

int			print_flags(t_lst *lst)
{
	int		len;

	len = 0;
	if (lst->flg.spc && !lst->flg.pls)
		len += print_flag(' ');
	if (lst->flg.sharp)
		len += print_flag('#');
	if (lst->flg.pls)
		len += print_flag('+');
	if (lst->flg.mns)
		len += print_flag('-');
	if (lst->flg.zero)
		len += print_flag('0');
	if (lst->flg.wth)
	{
		ft_putnbr((lst->flg.wth < 0 ? -(lst->flg.wth) : lst->flg.wth));
		len += ft_nbrlen((lst->flg.wth < 0 ? -(lst->flg.wth) : lst->flg.wth));
	}
	if (lst->flg.point)
	{
		len += print_flag('.');
		ft_putnbr(lst->flg.prc);
		len += ft_nbrlen(lst->flg.prc);
	}
	return (len);
}

int			other_conv(t_lst *lst, va_list ap)
{
	int		len;

	if (ft_strchr(lst->str, '%'))
		return (-1);
	(void)ap;
	remove_char(&(lst->str), "#-+ lhL.0123456789");
	len = conv_s_body(lst, lst->str);
	return (len);
}
