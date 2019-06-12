#include <stdlib.h>
#include "ft_sha256.h"
#include "libft.h"
#include "ft_printf.h"

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

void			sha256_exec(t_md5sha *sha256, char *msg, size_t len, bool file)
{
	if (msg == NULL)
		return ;
	if (sha256->opt.reverse == false && sha256->opt.quiet == false && file)
		ft_printf("SHA256 (%s) = ", sha256->av[sha256->index_file]);
	if (sha256->opt.reverse == false && sha256->opt.quiet == false && !file)
		ft_printf("SHA256 (\"%s\") = ", msg);
	ft_sha256_body(sha256, msg, len);
	ft_sha256_print_hash(sha256);
	if (sha256->opt.reverse && sha256->opt.quiet == false && file)
		ft_printf("  %s", sha256->av[sha256->index_file]);
	else if (sha256->opt.reverse && sha256->opt.quiet == false && !file)
		ft_printf(" \"%s\"", msg);
	ft_printf("\n");
	ft_strdel(&msg);
	sha256_reset_parts(sha256);
}

void			ft_sha256_file(t_md5sha *sha256)
{
	t_file		file;

	read_fd(0, &file);
	if (sha256->opt.in)
		ft_printf("%s", file.content);
	ft_sha256_body(sha256, file.content, file.len);
	free(file.content);
	ft_sha256_print_hash(sha256);
	ft_printf("\n");
	sha256_reset_parts(sha256);
}

int				ft_sha256(int ac, char **av)
{
	t_md5sha	sha256;
	t_file		file;
	char		*msg;

	sha256_init(&sha256);
	msg = sha256_opt(&sha256, ac, av);
	if ((!sha256.opt.string && !sha256.opt.file) || sha256.opt.in)
	{
		ft_sha256_file(&sha256);
	}
	if (sha256.opt.string)
		sha256_exec(&sha256, msg, ft_strlen(msg), false);
	if (sha256.opt.file)
	{
		while (sha256.index_file < ac)
		{
			if (read_file(sha256.av[sha256.index_file], &file) != NULL)
				sha256_exec(&sha256, file.content, file.len, true);
			free(file.content);
			sha256.index_file++;
		}
	}
	return (0);
}
