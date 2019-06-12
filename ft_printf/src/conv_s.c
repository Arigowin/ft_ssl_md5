/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:08 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:08 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

void		nullinbuff(char **str, char **buff)
{
	ft_bzero(*str, ft_strlen(*str) + 1);
	*buff = "(null)";
}

void		reduce(t_lst *lst, char **str, char *s2, int dir)
{
	int			j;
	int			len;

	j = 0;
	len = ft_strlen(s2);
	if (dir == 0 && lst->flg.wth > 0 && lst->flg.wth > len
			&& lst->flg.wth - len > lst->flg.wth - lst->flg.prc)
		j = lst->flg.wth - len;
	else if (dir == 0 && lst->flg.wth > 0 && lst->flg.wth > lst->flg.prc)
		j = lst->flg.wth - lst->flg.prc;
	ft_memcpy((*str) + j, s2, lst->flg.prc);
}

void		ft_cat(t_lst *lst, char **str, char *s2, int dir)
{
	int			j;
	int			len;

	j = 0;
	len = ft_strlen(s2);
	if (lst->flg.wth < len)
	{
		ft_strdel(str);
		*str = ft_strdup(s2);
		return ;
	}
	if (dir == 0 && lst->flg.wth > len)
		j = lst->flg.wth - len;
	ft_memcpy((*str) + j, s2, len);
}

int			conv_s_body(t_lst *lst, char *buff)
{
	char		*str;
	int			dir;
	int			len;

	dir = (lst->flg.wth < 0 ? 1 : 0);
	if (lst->flg.wth < 0)
		lst->flg.wth = -lst->flg.wth;
	if (NULL == (str = ft_strnew(1 + lst->flg.wth + ft_strlen(buff))))
		return (-1);
	if (buff == NULL && (lst->flg.prc >= 6 || lst->flg.prc == 0))
		nullinbuff(&str, &buff);
	ft_add_n_char(&str, (lst->flg.zero ? '0' : ' '), lst->flg.wth);
	len = ft_strlen(buff);
	if (lst->flg.prc > 0 && len > 0 && lst->flg.prc < len)
		reduce(lst, &str, buff, dir);
	else
		ft_cat(lst, &str, buff, dir);
	if (lst->flg.prc == 0 && lst->flg.point)
		ft_memset(str, ' ', ft_strlen(str));
	len = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (len);
}

int			conv_s(t_lst *lst, va_list ap)
{
	char		*buff;
	int			len;

	buff = va_arg(ap, char *);
	len = conv_s_body(lst, buff);
	return (len);
}
