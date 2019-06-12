#include <stdlib.h>
#include "ft_sha256.h"
#include "libft.h"
#include "ft_printf.h"

void			sha256_reset_parts(t_mdsha *sha256)
{
	sha256->parts[0] = INIT_SHA256_A;
	sha256->parts[1] = INIT_SHA256_B;
	sha256->parts[2] = INIT_SHA256_C;
	sha256->parts[3] = INIT_SHA256_D;
	sha256->parts[4] = INIT_SHA256_E;
	sha256->parts[5] = INIT_SHA256_F;
	sha256->parts[6] = INIT_SHA256_G;
	sha256->parts[7] = INIT_SHA256_H;
}

void			sha256_exec(t_mdsha *sha256, char *msg, size_t len, bool file)
{
	if (msg == NULL)
		return ;
	if (sha256->opt->reverse == false && sha256->opt->quiet == false && file)
		ft_printf("SHA256(%s)= ", sha256->opt->av[sha256->opt->index_file]);
	if (sha256->opt->reverse == false && sha256->opt->quiet == false && !file)
		ft_printf("SHA256 (\"%s\") = ", msg);
	ft_sha256_body(sha256, msg, len);
	ft_sha256_print_hash(sha256);
	if (sha256->opt->reverse && sha256->opt->quiet == false && file)
		ft_printf("  %s", sha256->opt->av[sha256->opt->index_file]);
	else if (sha256->opt->reverse && sha256->opt->quiet == false && !file)
		ft_printf(" \"%s\"", msg);
	ft_printf("\n");
	ft_strdel(&msg);
	sha256_reset_parts(sha256);
}

void			ft_sha256_file(t_mdsha *sha256)
{
	t_msg		file;

	read_fd(0, &file);
	if (sha256->opt->in)
		ft_printf("%s", file.content);
	ft_sha256_body(sha256, file.content, file.len);
	free(file.content);
	ft_sha256_print_hash(sha256);
	ft_printf("\n");
	sha256_reset_parts(sha256);
}

void			ft_sha256_strings(t_mdsha *sha256)
{
	t_msg		*tmp;

	tmp = sha256->opt->msg;
	while (tmp != NULL)
	{
		sha256_exec(sha256, tmp->content, tmp->len, false);
		sha256_reset_parts(sha256);
		tmp = tmp->next;
	}
}

int				ft_sha256(t_opt *opt, int ac)
{
	t_mdsha		sha256;
	t_msg		f;

	sha256_reset_parts(&sha256);
	sha256.opt = opt;
	if ((!sha256.opt->string && !sha256.opt->file) || sha256.opt->in)
	{
		ft_sha256_file(&sha256);
	}
	if (sha256.opt->string)
		ft_sha256_strings(&sha256);
	if (sha256.opt->file)
	{
		while (sha256.opt->index_file < ac)
		{
			if (read_file(sha256.opt->av[sha256.opt->index_file], &f) != NULL)
				sha256_exec(&sha256, f.content, f.len, true);
			sha256.opt->index_file++;
		}
	}
	return (0);
}
