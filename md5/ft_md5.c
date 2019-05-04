#include "ft_ssl.h"
#include "ft_md5.h"
#include "libft.h"
#include "ft_printf.h"

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

void			md5_exec(t_md5sha *md5, char *msg, size_t len, bool file)
{
	if (msg == NULL)
		return ;
	if (md5->opt.reverse == false && md5->opt.quiet == false && file)
		ft_printf("MD5 (%s) = ", md5->av[md5->index_file]);
	if (md5->opt.reverse == false && md5->opt.quiet == false && !file)
		ft_printf("MD5 (\"%s\") = ", msg);
	ft_md5_body(md5, msg, len);
	ft_md5_print_hash(md5);
	if (md5->opt.reverse && md5->opt.quiet == false && file)
		ft_printf("  %s", md5->av[md5->index_file]);
	else if (md5->opt.reverse && md5->opt.quiet == false && !file)
		ft_printf(" \"%s\"", msg);
	ft_printf("\n");
	ft_strdel(&msg);
	md5_reset_parts(md5);
}

void			ft_md5_file(t_md5sha *md5)
{
	t_file		file;

	read_fd(0, &file);
	if (md5->opt.in)
		ft_printf("%s", file.content);
	ft_md5_body(md5, file.content, file.len);
	ft_md5_print_hash(md5);
	ft_printf("\n");
	md5_reset_parts(md5);
}

int				ft_md5(int ac, char **av)
{
	t_md5sha	md5;
	t_file		file;
	char		*msg;

	md5_init(&md5);
	msg = md5_opt(&md5, ac, av);
	if ((!md5.opt.string && !md5.opt.file) || md5.opt.in)
		ft_md5_file(&md5);
	if (md5.opt.string)
		md5_exec(&md5, msg, ft_strlen(msg), false);
	if (md5.opt.file)
	{
		while (md5.index_file < ac)
		{
			read_file(md5.av[md5.index_file], &file);
			md5_exec(&md5, file.content, file.len, true);
			md5.index_file++;
		}
	}
	return (1);
}
