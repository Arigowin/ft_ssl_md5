#include "ft_ssl.h"
#include "ft_md5.h"
#include "libft.h"

void			md5_opt(t_md5 *md5, int ac, char **av)
{
	int			i;

	i = 1;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-p") == 0)
			md5->opt.in = true;
		else if (ft_strcmp(av[i], "-q") == 0)
			md5->opt.quiet = true;
		else if (ft_strcmp(av[i], "-r") == 0)
			md5->opt.reverse = true;
		else if (ft_strcmp(av[i], "-s") == 0)
		{
			md5->opt.string = true;
			md5->initial_message = av[++i];
			md5->initial_len = ft_strlen(md5->initial_message);
		}
		else
		{
			md5->opt.file = true;
			md5->filename = av[i];
		}
	}
}

void			md5_reset_parts(t_md5 *md5)
{
	md5->parts.a = INIT_A;
	md5->parts.b = INIT_B;
	md5->parts.c = INIT_C;
	md5->parts.d = INIT_D;
}

void			md5_init(t_md5 *md5)
{
	md5->opt.in = false;
	md5->opt.quiet = false;
	md5->opt.reverse = false;
	md5->opt.string = false;
	md5->opt.file = false;
	md5_reset_parts(md5);
	md5->initial_message = NULL;
}

int				ft_md5(int ac, char **av)
{
	char		*msg[3];
	int			i;
	int			j;
	t_md5		md5;

	md5_init(&md5);
	md5_opt(&md5, ac, av);
	i = 0;
	if (md5.initial_message != NULL)
		msg[i++] = ft_strdup(md5.initial_message);
	if (md5.opt.file)
		msg[i++] = read_file(md5.filename);
	/* msg[i++] = read_fd(0); */
	j = 0;
	while (j < i)
	{
		md5.initial_message = msg[j];
		ft_md5_body(&md5);
		ft_md5_print_hash(&md5);
		md5_reset_parts(&md5);
		j++;
	}
	return (0);
}
