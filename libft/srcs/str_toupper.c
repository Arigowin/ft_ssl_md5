/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_toupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:06:57 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:06:59 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*str_toupper(char *str)
{
	char				*ret;
	int					i;

	ret = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		ret[i] = ft_toupper(str[i]);
		i++;
	}
	return (ret);
}
