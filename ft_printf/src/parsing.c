/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:11 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:11 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "ft_printf.h"

t_type		check_type(char c)
{
	if (c == 'c')
		return (CHAR);
	if (c == 's')
		return (STR);
	if (c == 'p')
		return (PTR);
	if (c == 'd' || c == 'i')
		return (INT);
	if (c == 'o')
		return (OCT);
	if (c == 'u')
		return (UINT);
	if (c == 'x')
		return (LHEX);
	if (c == 'X')
		return (UHEX);
	if (c == 'f')
		return (FLT);
	if (c == '%')
		return (PCT);
	return (OTHER);
}

void		parse_more_flg(t_lst *tmp, t_type type)
{
	tmp->flg.wth = get_width(tmp);
	tmp->flg.prc = get_precision(tmp->str);
	if (((type == CHAR || type == STR || type == PTR)
				&& (tmp->flg.hh || tmp->flg.h || tmp->flg.l || tmp->flg.ll))
			|| (ft_strncount(tmp->str, 'l') > 2
				|| ft_strncount(tmp->str, 'h') > 2))
		tmp->type = OTHER;
}

void		parse_flg(t_lst **lst, t_type type, char *str)
{
	t_lst	*tmp;
	int		len;

	lst_add(lst, type, str);
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->flg.hh = ft_strstr(tmp->str, "hh") != NULL;
	tmp->flg.h = ft_strchr(tmp->str, 'h') != NULL;
	tmp->flg.ll = ft_strstr(tmp->str, "ll") != NULL;
	tmp->flg.l = ft_strchr(tmp->str, 'l') != NULL;
	tmp->flg.upperl = ft_strchr(tmp->str, 'L') != NULL;
	tmp->flg.sharp = ft_strchr(tmp->str, '#') != NULL;
	tmp->flg.mns = ft_strchr(tmp->str, '-') != NULL;
	tmp->flg.pls = ft_strchr(tmp->str, '+') != NULL;
	tmp->flg.spc = ft_strchr(tmp->str, ' ') != NULL;
	tmp->flg.point = ft_strchr(tmp->str, '.') != NULL;
	len = ft_strlen(tmp->str);
	tmp->flg.zero = (!tmp->flg.mns && (tmp->str[0] == '0' || (len > 1
					&& !ft_isdigit(tmp->str[0]) && tmp->str[0] != '.'
					&& (tmp->str[1] == '0' || (len > 2
							&& !ft_isdigit(tmp->str[1])
							&& tmp->str[2] == '0')))));
	parse_more_flg(tmp, type);
}

void		parse_specflg(t_lst **lst, const char *fmt, size_t *st, size_t *i)
{
	(*i)++;
	while (*i < ft_strlen(fmt) && (ft_strchr("#0-+ hlL.", fmt[*i])
				|| ft_isdigit(fmt[*i])))
		(*i)++;
	if (*st + 1 >= ft_strlen(fmt))
		*st -= 1;
	parse_flg(lst, check_type(fmt[*i]),
			ft_strsub(fmt, *st + 1, (*i - *st)));
	*st = *i + 1;
}

void		parse(t_lst **lst, const char *format)
{
	size_t	i;
	size_t	start;

	start = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (i != start)
			{
				parse_flg(lst, DFLT, ft_strsub(format, start, i - start));
				start = i;
			}
			parse_specflg(lst, format, &start, &i);
		}
		i++;
	}
	if (i != start)
		parse_flg(lst, DFLT, ft_strsub(format, start, i - start));
}
