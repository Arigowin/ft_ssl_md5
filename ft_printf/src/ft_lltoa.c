/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:19:18 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:41:33 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

static int		ft_puttbl2(unsigned long long int n, int len,
		int sign, char **str)
{
	int	i;

	if (n > 9)
		i = ft_puttbl2(n / 10, len + 1, sign, str);
	else
	{
		*str = ft_strnew(len + 1);
		i = sign;
	}
	if (*str != NULL)
		(*str)[i] = (n % 10) + '0';
	return (i + 1);
}

char			*ft_lltoa(long long int n)
{
	char	*str;

	if (n < 0)
	{
		ft_puttbl2(-n, 1, 1, &str);
		if (str != NULL)
			str[0] = '-';
	}
	else
		ft_puttbl2(n, 0, 0, &str);
	return (str);
}
