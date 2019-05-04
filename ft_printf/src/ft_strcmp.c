/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:57 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:57 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char		*s_one;
	const unsigned char		*s_two;

	s_one = (const unsigned char*)s1;
	s_two = (const unsigned char*)s2;
	while (*s_one == *s_two && *s_one != '\0')
	{
		s_one++;
		s_two++;
	}
	return (*s_one - *s_two);
}
