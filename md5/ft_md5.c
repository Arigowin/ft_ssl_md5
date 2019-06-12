#include <stdlib.h>
#include "ft_ssl.h"
#include "ft_md5.h"
#include "libft.h"
#include "ft_printf.h"

void			md5_reset_parts(t_mdsha *md5)
{
	md5->parts[0] = 0x67452301;
	md5->parts[1] = 0xefcdab89;
	md5->parts[2] = 0x98badcfe;
	md5->parts[3] = 0x10325476;
}

void			md5_exec(t_mdsha *md5, char *msg, size_t len, bool file)
{
	if (msg == NULL)
		return ;
	if (md5->opt->reverse == false && md5->opt->quiet == false && file)
		ft_printf("MD5 (%s) = ", md5->opt->av[md5->opt->index_file]);
	if (md5->opt->reverse == false && md5->opt->quiet == false && !file)
		ft_printf("MD5 (\"%s\") = ", msg);
	ft_md5_body(md5, msg, len);
	ft_md5_print_hash(md5);
	if (md5->opt->reverse && md5->opt->quiet == false && file)
		ft_printf(" %s", md5->opt->av[md5->opt->index_file]);
	else if (md5->opt->reverse && md5->opt->quiet == false && !file)
		ft_printf(" \"%s\"", msg);
	ft_printf("\n");
	ft_strdel(&msg);
	md5_reset_parts(md5);
}

void			ft_md5_file(t_mdsha *md5)
{
	t_msg		file;

	read_fd(0, &file);
	if (md5->opt->in)
		ft_printf("%s", file.content);
	ft_md5_body(md5, file.content, file.len);
	free(file.content);
	ft_md5_print_hash(md5);
	ft_printf("\n");
	md5_reset_parts(md5);
}

void			ft_md5_strings(t_mdsha *md5)
{
	t_msg		*tmp;

	tmp = md5->opt->msg;
	while (tmp != NULL)
	{
		md5_exec(md5, tmp->content, tmp->len, false);
		md5_reset_parts(md5);
		tmp = tmp->next;
	}
}

int				ft_md5(t_opt *opt, int ac)
{
	t_mdsha		md5;
	t_msg		file;

	md5_reset_parts(&md5);
	md5.opt = opt;
	if ((!md5.opt->string && !md5.opt->file) || md5.opt->in)
		ft_md5_file(&md5);
	if (md5.opt->string)
		ft_md5_strings(&md5);
	if (md5.opt->file)
	{
		while (md5.opt->index_file < ac)
		{
			if (read_file(md5.opt->av[md5.opt->index_file], &file) != NULL)
				md5_exec(&md5, file.content, file.len, true);
			md5.opt->index_file++;
		}
	}
	return (1);
}
