/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:05:57 by dolewski          #+#    #+#             */
/*   Updated: 2019/05/04 17:05:57 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char				*ft_strdup(const char *s1)
{
	size_t			i;
	char			*duplicate;
	size_t			str_len;

	i = 0;
	str_len = ft_strlen(s1);
	duplicate = (char*)malloc(str_len + 1);
	if (!duplicate)
		return (NULL);
	while (i < str_len)
	{
		duplicate[i] = s1[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
