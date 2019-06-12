/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:09 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:09 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void		ft_add_char_front(char c, char **str, int nb, int len)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	j = (nb - len <= 0 ? 0 : nb - len);
	cpy = ft_strnew(len);
	ft_memcpy(cpy, *str, len);
	while (i < len)
	{
		(*str)[j] = cpy[i];
		i++;
		j++;
	}
	(*str)[j] = 0;
	i = 0;
	while (i < (nb - len))
		(*str)[i++] = c;
	ft_strdel(&cpy);
}
