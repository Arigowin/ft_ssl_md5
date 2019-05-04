/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:54 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:54 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (size != 0)
	{
		tmp = malloc(size);
		if (tmp != NULL)
			ft_bzero(tmp, size);
		return (tmp);
	}
	return (NULL);
}
