/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:01:03 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:01:05 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_get_index(char *tab, char c)
{
	size_t		i;

	i = 0;
	while (i < ft_strlen(tab))
	{
		if (tab[i] == c)
			break ;
		i++;
	}
	return (i);
}
