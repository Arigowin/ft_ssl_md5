/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_o2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:08 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:08 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void			add_o2(char **str)
{
	char	*buff;

	buff = ft_strnew(ft_strlen(*str) + 1);
	buff[0] = '0';
	ft_memcpy(buff + 1, *str, ft_strlen(*str));
	ft_strdel(str);
	*str = buff;
}

void			add_o(t_lst *lst, char **str, char *nb)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(nb);
	if (lst->flg.wth <= 0 || ((lst->flg.wth < 0 && len >= -lst->flg.wth)
				|| len >= lst->flg.wth))
	{
		if ((*str)[ft_strlen(*str) - 1] == ' ')
		{
			(*str)[0] = '0';
			i = -1;
			while (nb[++i])
				(*str)[i + 1] = nb[i];
		}
		else
			add_o2(str);
	}
	else
	{
		while ((*str)[i] && !ft_isdigit((*str)[i]))
			i++;
		(*str)[(i <= 0 ? 0 : i - 1)] = '0';
	}
}
