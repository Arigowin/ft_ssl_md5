/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:11 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:11 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int			no_conv(t_lst *lst, va_list ap)
{
	(void)ap;
	ft_putstr(lst->str);
	return (ft_strlen(lst->str));
}
