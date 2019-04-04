#include "ft_sha256.h"
#include "libft.h"

char			*sha256_opt(t_md5sha *sha256, int ac, char **av)
{
	char		*tmp;
	int			i;

	i = 1;
	tmp = NULL;
	while (++i < ac)
	{
		if (!sha256->opt.file && ft_strcmp(av[i], "-p") == 0)
			sha256->opt.in = true;
		else if (!sha256->opt.file && ft_strcmp(av[i], "-q") == 0)
			sha256->opt.quiet = true;
		else if (!sha256->opt.file && ft_strcmp(av[i], "-r") == 0)
			sha256->opt.reverse = true;
		else if (!sha256->opt.file && ft_strcmp(av[i], "-s") == 0)
		{
			sha256->opt.string = true;
			tmp = ft_strdup(av[++i]);
		}
		else
		{
			sha256->opt.file = true;
			sha256->index_file = i;
			sha256->av = av;
			break ;
		}
	}
	return (tmp);
}

void			sha256_reset_parts(t_md5sha *sha256)
{
	sha256->parts.a = INIT_SHA256_A;
	sha256->parts.b = INIT_SHA256_B;
	sha256->parts.c = INIT_SHA256_C;
	sha256->parts.d = INIT_SHA256_D;
	sha256->parts.e = INIT_SHA256_E;
	sha256->parts.f = INIT_SHA256_F;
	sha256->parts.g = INIT_SHA256_G;
	sha256->parts.h = INIT_SHA256_H;
}

void			sha256_init(t_md5sha *sha256)
{
	sha256->opt.in = false;
	sha256->opt.quiet = false;
	sha256->opt.reverse = false;
	sha256->opt.string = false;
	sha256->opt.file = false;
	sha256_reset_parts(sha256);
}

void			sha256_exec(t_md5sha *sha256, char *msg, bool file)
{
	if (msg == NULL)
		return ;
	if (sha256->opt.reverse == false && sha256->opt.quiet == false && file)
		printf("SHA256 (%s) = ", sha256->av[sha256->index_file]);
	if (sha256->opt.reverse == false && sha256->opt.quiet == false && !file)
		printf("SHA256 (\"%s\") = ", msg);
	ft_sha256_body(sha256, msg);
	ft_sha256_print_hash(sha256);
	if (sha256->opt.reverse && sha256->opt.quiet == false && file)
		printf("  %s", sha256->av[sha256->index_file]);
	else if (sha256->opt.reverse && sha256->opt.quiet == false && !file)
		printf(" \"%s\"", msg);
	printf("\n");
	ft_strdel(&msg);
	sha256_reset_parts(sha256);
}

int			ft_sha256(int ac, char **av)
{
	t_md5sha sha256;
	char	*msg;
	char	*tmp;

	sha256_init(&sha256);
	msg = sha256_opt(&sha256, ac, av);
	if ((!sha256.opt.string && !sha256.opt.file) || sha256.opt.in)
	{
		tmp = read_fd(0);
		if (sha256.opt.in)
			printf("%s", tmp);
		ft_sha256_body(&sha256, tmp);
		ft_sha256_print_hash(&sha256);
		printf("\n");
		sha256_reset_parts(&sha256);
	}
	if (sha256.opt.string)
		sha256_exec(&sha256, msg, false);
	if (sha256.opt.file)
	{
		while (sha256.index_file < ac)
		{
			sha256_exec(&sha256, read_file(sha256.av[sha256.index_file]), true);
			sha256.index_file++;
		}
	}
	return (0);
}
