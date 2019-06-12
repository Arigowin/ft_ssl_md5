/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_pct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:08 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:26:32 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int			conv_pct(t_lst *lst, va_list ap)
{
	int		len;

	(void)ap;
	if (ft_strstr(lst->str, ".0"))
	{
		ft_putchar('%');
		len = 1;
	}
	else
		len = conv_s_body(lst, "%");
	return (len);
}
