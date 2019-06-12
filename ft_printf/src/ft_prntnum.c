/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prntnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:10 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:41:46 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void		ft_prntnum(unsigned long num, int base, char sign, char *outbuf)
{
	int		i;
	int		j;

	i = 29;
	j = 0;
	while ((num > 0 || i == 29))
	{
		outbuf[i] = "0123456789abcdef"[num % base];
		i--;
		num = num / base;
	}
	if (sign != ' ')
	{
		outbuf[0] = sign;
		++j;
	}
	while (++i < 30)
		outbuf[j++] = outbuf[i];
	outbuf[j] = 0;
}
