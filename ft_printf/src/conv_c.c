/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:07 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:07 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int			conv_c(t_lst *lst, va_list ap)
{
	int			len;

	len = 1;
	if (lst->flg.wth > 0)
	{
		ft_print_n_char((lst->flg.zero ? '0' : ' '), lst->flg.wth - 1);
		len = lst->flg.wth;
	}
	ft_putchar(va_arg(ap, int));
	if (lst->flg.wth < 0)
	{
		ft_print_n_char((lst->flg.zero ? '0' : ' '), -(lst->flg.wth) - 1);
		len = -lst->flg.wth;
	}
	return (len);
}
