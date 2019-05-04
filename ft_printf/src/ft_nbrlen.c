/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:54 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:54 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_nbrlen(int nb)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nb);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}
