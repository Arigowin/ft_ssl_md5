/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:10 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:10 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void		ft_ptr_to_hex(const void *ptr, char (*res)[16])
{
	char	alpha[16];
	size_t	addr;
	int		i;

	ft_memcpy(alpha, "0123456789abcdef", 16);
	ft_bzero(res, 17);
	ft_memset(res, '0', 16);
	i = 15;
	addr = (size_t)ptr;
	(*res)[i--] = alpha[addr % 16];
	while ((addr /= 16) > 0 && i > -1)
		(*res)[i--] = alpha[addr % 16];
}
