/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:55 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:55 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_lst		*lst;
	int			len;

	lst = NULL;
	va_start(ap, format);
	parse(&lst, format);
	len = print_all(lst, ap);
	lst_free(&lst);
	va_end(ap);
	return (len);
}
