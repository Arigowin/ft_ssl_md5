/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:58 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:01:01 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long		ft_atoh(char *str)
{
	static char		charset[16] = "0123456789ABCDEF";
	unsigned long	out;
	size_t			i;

	out = 0;
	i = 0;
	while (i < ft_strlen(str))
	{
		out = out << 8 | (ft_get_index(charset, str[i]) << 4
				| ft_get_index(charset, str[i + 1]));
		i += 2;
	}
	return (out);
}
