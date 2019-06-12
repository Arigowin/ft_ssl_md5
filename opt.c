#include <stdlib.h>
#include "libft.h"
#include "ft_ssl.h"

void			init_opt(t_opt *opt)
{
	opt->in = false;
	opt->quiet = false;
	opt->reverse = false;
	opt->string = false;
	opt->msg = NULL;
	opt->file = false;
	opt->index_file = 0;
	opt->av = NULL;
}

void			handle_opt(t_opt *opt, char **av, int *i)
{
	size_t	j;

	j = 0;
	while (av[*i][++j])
	{
		if (!opt->file && av[*i][j] == 'p')
			opt->in = true;
		if (!opt->file && av[*i][j] == 'q')
			opt->quiet = true;
		if (!opt->file && av[*i][j] == 'r')
			opt->reverse = true;
		if (!opt->file && av[*i][j] == 's')
		{
			opt_s(opt, av, i, j);
			break ;
		}
	}
}

t_opt			get_opt(int ac, char **av)
{
	t_opt		opt;
	int			i;

	i = 1;
	init_opt(&opt);
	while (++i < ac)
	{
		if (!opt.file && av[i][0] == '-')
			handle_opt(&opt, av, &i);
		else
		{
			opt_more(&opt, av, i);
			break ;
		}
	}
	return (opt);
}

void			free_opt(t_opt *opt)
{
	t_msg		*tmp;

	while (opt->msg != NULL)
	{
		tmp = NULL;
		tmp = opt->msg->next;
		free(opt->msg);
		opt->msg = tmp;
	}
}
