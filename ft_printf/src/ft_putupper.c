/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:56 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:56 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putupper(char const *s)
{
	size_t i;

	i = 0;
	while (s && i < ft_strlen(s))
	{
		ft_putchar(ft_toupper(s[i]));
		i++;
	}
}
