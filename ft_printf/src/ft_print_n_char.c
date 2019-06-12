/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:10 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:10 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void		ft_print_n_char(char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i++;
	}
}
