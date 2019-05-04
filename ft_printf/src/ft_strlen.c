/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:57 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:57 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ft_strlen(const char *s)
{
	size_t		count;

	count = 0;
	if (s)
		while (*s != '\0')
		{
			count++;
			s++;
		}
	return (count);
}
