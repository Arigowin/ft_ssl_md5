/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:53 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:53 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_add_char_back(char c, char **str, int nb, int start)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		(*str)[start + i] = c;
		i++;
	}
	(*str)[start + i] = '\0';
}
