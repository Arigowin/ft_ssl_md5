/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:10 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:10 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

size_t		ft_nbrlen(long long int nb)
{
	char	*tmp;
	int		len;

	tmp = ft_itoa(nb);
	len = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (len);
}
