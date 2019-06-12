/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_symbole.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:10 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:10 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

char		*add_syb(char c, char *str)
{
	char	*buff;
	int		i;
	int		j;
	int		syb;

	syb = 0;
	buff = ft_strnew(ft_strlen(str) + 1);
	while (!ft_isdigit(str[syb]) && syb < (int)ft_strlen(str))
		syb++;
	if (syb == (int)ft_strlen(str))
		return (str);
	i = 0;
	j = 0;
	while (i < syb && str[i])
		buff[j++] = str[i++];
	buff[j++] = c;
	while (str[syb])
	{
		buff[j] = str[syb];
		j++;
		syb++;
	}
	return (buff);
}

char		*offset(char c, char *str)
{
	char	*tmp;
	int		len;

	len = ft_strlen(str);
	if (str[len - 1] == ' ')
	{
		tmp = ft_strnew(len);
		ft_memcpy(tmp + 1, str, len - 1);
		tmp[0] = c;
		return (tmp);
	}
	tmp = ft_strdup(str);
	tmp[0] = c;
	return (tmp);
}

int			count_char(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}

void		ft_add_symbole(t_lst *lst, char **str, int syb[2])
{
	char	*tmp;
	int		len;

	len = ft_strlen(*str);
	if (syb[0])
		tmp = add_syb('-', *str);
	else if (syb[1])
		tmp = add_syb('+', *str);
	else if (lst->flg.wth <= len && (*str)[0] != ' ' && lst->flg.spc)
	{
		if ((lst->type == FLT && (count_char(*str, '0') > 1
						|| (*str)[len - 1] == ' ')) || (lst->type != FLT
					&& len > 1 && lst->flg.wth != 0 && ((*str)[len - 1] == ' '
						|| (lst->flg.prc == 0 && lst->flg.zero
							&& (*str)[0] == '0'))))
			tmp = offset(' ', *str);
		else
			tmp = add_syb(' ', *str);
	}
	else
		return ;
	ft_strdel(str);
	*str = tmp;
}
