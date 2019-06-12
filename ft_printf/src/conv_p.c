/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:08 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:08 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void		join_0x(char **str)
{
	char	*buff;
	int		len;

	len = ft_strlen(*str);
	buff = ft_strnew(len + 2);
	ft_memcpy(buff + 2, *str, len);
	buff[0] = '0';
	buff[1] = 'x';
	ft_strdel(str);
	*str = buff;
}

void		add_0x(void *ptr, char **str)
{
	int		i;
	int		j;

	i = 0;
	if (ptr == NULL)
		return ;
	while ((*str)[i] == '0')
		i++;
	if (i == 0)
		return (join_0x(str));
	ft_memset(*str, ' ', i);
	(*str)[i - 1] = 'x';
	(*str)[i - 2] = '0';
	j = 0;
	i -= 2;
	while ((*str)[i])
		(*str)[j++] = (*str)[i++];
	ft_memset(*str + j, '\0', (i - j) + 1);
}

int			conv_p(t_lst *lst, va_list ap)
{
	char		buff[16];
	char		*str;
	void		*ptr;
	int			w;
	int			len;

	w = (lst->flg.wth < 0 ? -lst->flg.wth : lst->flg.wth);
	lst->flg.prc = 0;
	str = ft_strnew(16 + w);
	ptr = va_arg(ap, void *);
	ft_bzero(buff, 16);
	if (ptr == NULL)
		ft_memcpy(buff, "0x0", 3);
	else
		ft_ptr_to_hex(ptr, &buff);
	ft_memcpy(str, buff, 16);
	ft_remove_char('0', &(lst->str));
	add_0x(ptr, &str);
	ft_add_char(lst, &str);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
