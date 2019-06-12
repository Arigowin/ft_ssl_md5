/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:11 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:11 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

int			ft_remove_char(char c, char **str)
{
	int		i;
	int		j;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
		{
			j = 0;
			while (j < (int)ft_strlen(*str))
			{
				i++;
				(*str)[j] = (*str)[i];
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}
