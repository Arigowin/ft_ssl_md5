/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:12 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:12 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int			print_all(t_lst *lst, va_list ap)
{
	t_lst		*tmp;
	int			len;
	int			tmp_len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		if ((tmp_len = conversion_manager(tmp, ap)) < 0)
			return (tmp_len);
		len += tmp_len;
		tmp = tmp->next;
	}
	return (len);
}
