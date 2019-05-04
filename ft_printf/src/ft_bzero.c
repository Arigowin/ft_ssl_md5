/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:53 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:53 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*save_ptr;

	i = 0;
	save_ptr = s;
	while (i < n)
	{
		*save_ptr = '\0';
		i++;
		save_ptr++;
	}
}
