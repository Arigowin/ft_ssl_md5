#include "ft_ssl.h"
#include "ft_md5.h"
#include "libft.h"

char			*md5_opt(t_md5sha *md5, int ac, char **av)
{
	char		*tmp;
	int			i;

	i = 1;
	tmp = NULL;
	while (++i < ac)
	{
		if (!md5->opt.file && ft_strcmp(av[i], "-p") == 0)
			md5->opt.in = true;
		else if (!md5->opt.file && ft_strcmp(av[i], "-q") == 0)
			md5->opt.quiet = true;
		else if (!md5->opt.file && ft_strcmp(av[i], "-r") == 0)
			md5->opt.reverse = true;
		else if (!md5->opt.file && ft_strcmp(av[i], "-s") == 0)
		{
			md5->opt.string = true;
			if ((tmp = ft_strdup(av[++i])) == NULL)
				return (NULL);
		}
		else
		{
			md5->opt.file = true;
			md5->index_file = i;
			md5->av = av;
			break ;
		}
	}
	return (tmp);
}

void			md5_reset_parts(t_md5sha *md5)
{
	md5->parts.a = INIT_MD5_A;
	md5->parts.b = INIT_MD5_B;
	md5->parts.c = INIT_MD5_C;
	md5->parts.d = INIT_MD5_D;
}

void			md5_init(t_md5sha *md5)
{
	md5->opt.in = false;
	md5->opt.quiet = false;
	md5->opt.reverse = false;
	md5->opt.string = false;
	md5->opt.file = false;
	md5_reset_parts(md5);
}

void			md5_exec(t_md5sha *md5, char *msg, bool file)
{
	if (msg == NULL)
		return ;
	if (md5->opt.reverse == false && md5->opt.quiet == false && file)
		printf("MD5 (%s) = ", md5->av[md5->index_file]);
	if (md5->opt.reverse == false && md5->opt.quiet == false && !file)
		printf("MD5 (\"%s\") = ", msg);
	ft_md5_body(md5, msg);
	ft_md5_print_hash(md5);
	if (md5->opt.reverse && md5->opt.quiet == false && file)
		printf("  %s", md5->av[md5->index_file]);
	else if (md5->opt.reverse && md5->opt.quiet == false && !file)
		printf(" \"%s\"", msg);
	printf("\n");
	ft_strdel(&msg);
	md5_reset_parts(md5);
}

int				ft_md5(int ac, char **av)
{
	t_md5sha	md5;
	char		*msg;
	char		*tmp;

	md5_init(&md5);
	if ((msg = md5_opt(&md5, ac, av)) == NULL)
	{
		printf("ft_ssl: md5: An error occured when handle option\n");
		return (-1);
	}
	if ((!md5.opt.string && !md5.opt.file) || md5.opt.in)
	{
		tmp = read_fd(0);
		if (md5.opt.in)
			printf("%s", tmp);
		ft_md5_body(&md5, tmp);
		ft_md5_print_hash(&md5);
		printf("\n");
		md5_reset_parts(&md5);
	}
	if (md5.opt.string)
		md5_exec(&md5, msg, false);
	if (md5.opt.file)
	{
		while (md5.index_file < ac)
		{
			md5_exec(&md5, read_file(md5.av[md5.index_file]), true);
			md5.index_file++;
		}
	}
	return (1);
}
