/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:52 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:52 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_add_char(t_lst *lst, char **str)
{
	int		len;

	len = (int)ft_strlen(*str);
	if (lst->flg.prc > 0)
		ft_add_char_front('0', str, lst->flg.prc, len);
	len = (int)ft_strlen(*str);
	if (lst->flg.wth && !lst->flg.prc && lst->flg.wth > len
			&& (lst->type == FLT || !lst->flg.point) && lst->flg.zero)
		ft_add_char_front('0', str, lst->flg.wth, len);
	else if (lst->flg.wth && lst->flg.wth > len)
		ft_add_char_front(' ', str, lst->flg.wth, len);
	len = (int)ft_strlen(*str);
	if (lst->flg.wth < 0)
		ft_add_char_back(' ', str, -(lst->flg.wth) - len, len);
}
