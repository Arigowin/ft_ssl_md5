/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaining_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolewski <dolewski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 09:00:07 by dolewski          #+#    #+#             */
/*   Updated: 2019/06/12 09:00:07 by dolewski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "ft_printf.h"

t_lst		*lst_add(t_lst **lst, t_type type, char *str)
{
	t_lst	*new;
	t_lst	*tmp;

	if (str == NULL || lst == NULL)
		return (NULL);
	if ((new = (t_lst *)malloc(sizeof(t_lst))) == NULL)
		return (NULL);
	new->type = type;
	new->str = str;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (new);
}

void		lst_free(t_lst **lst)
{
	t_lst	*tmp;

	tmp = NULL;
	while (lst && *lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_strdel(&(tmp->str));
		free(tmp);
	}
	tmp = NULL;
	*lst = NULL;
}
