/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:11 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:11 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int			get_width(t_lst *lst)
{
	int		wth;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while (i < (int)ft_strlen(lst->str) && ft_strchr("#0-+ ", (lst->str)[i]))
		i++;
	if (lst->flg.mns)
		sign = -sign;
	wth = ft_atoi((lst->str) + i);
	if (wth < 0)
		wth = -wth;
	return (wth == 0 ? wth : wth * sign);
}

int			get_precision(char *str)
{
	int		prc;
	char	*tmp;

	tmp = ft_strchr(str, '.');
	if (tmp == NULL)
		return (0);
	prc = ft_atoi(tmp + 1);
	return (prc);
}
