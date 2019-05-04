/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:54 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:54 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_itolet(unsigned int nb)
{
	return (nb + 'a' - 10);
}

static int		ft_puttbl_base(unsigned int n, char *t, char **str, size_t b)
{
	int	i;

	if (n > b - 1)
	{
		t[0] += 1;
		i = ft_puttbl_base(n / b, t, str, b);
	}
	else
	{
		*str = ft_strnew(t[0]);
		i = t[1];
	}
	if (*str != NULL)
	{
		if (b > 10 && (n % b) > 9)
			(*str)[i] = ft_itolet(n % b);
		else
			(*str)[i] = (n % b) + '0';
	}
	return (i + 1);
}

char			*ft_itoa_base(int n, int base)
{
	char	*str;
	char	*t;

	str = NULL;
	t = ft_strnew(2);
	if (base >= 2 && base <= 36)
	{
		if (n < 0)
		{
			t[0] = 1;
			t[1] = 1;
			ft_puttbl_base(-n, t, &str, base);
			if (str != NULL)
				str[0] = '-';
		}
		else
		{
			t[0] = 0;
			t[1] = 0;
			ft_puttbl_base(n, t, &str, base);
		}
	}
	return (str);
}
