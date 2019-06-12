#include <stdlib.h>
#include "libft.h"
#include "ft_ssl.h"

t_msg			*new_msg(char *msg)
{
	t_msg		*new;

	new = (t_msg *)malloc(sizeof(t_msg));
	if (new != NULL)
	{
		new->content = ft_strdup(msg);
		new->len = ft_strlen(new->content);
		new->next = NULL;
	}
	return (new);
}

void			add_msg(t_opt *opt, char *msg)
{
	t_msg		*tmp;

	if (opt->msg == NULL)
	{
		opt->msg = new_msg(msg);
		return ;
	}
	tmp = opt->msg;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new_msg(msg);
}

void			opt_more(t_opt *opt, char **av, int i)
{
	opt->file = true;
	opt->index_file = i;
	opt->av = av;
}

void			opt_s(t_opt *opt, char **av, int *i, size_t j)
{
	char	*tmp;

	opt->string = true;
	if (j == ft_strlen(av[*i]) - 1)
		add_msg(opt, av[++(*i)]);
	else
	{
		tmp = ft_strsub(av[*i], j + 1, ft_strlen(av[*i]));
		add_msg(opt, tmp);
	}
}
