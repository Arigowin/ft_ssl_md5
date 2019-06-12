/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_n_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:09 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:09 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void		ft_add_n_char(char **str, char c, int n)
{
	int		i;

	i = 0;
	while (str && *str && i < n)
	{
		(*str)[i] = c;
		i++;
	}
}
