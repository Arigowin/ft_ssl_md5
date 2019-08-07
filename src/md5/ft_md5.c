#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_ssl.h"

void			md5_exec(t_mdsha *md5, char *msg, size_t len, bool file)
{
	uint8_t		digest[MD5_DIGEST_LENGTH];

	if (msg == NULL)
		return ;
	ft_mdsha_print_beg(md5->opt, "MD5", msg, file);
	ft_md5init(md5);
	ft_md5update(md5, msg, len);
	ft_md5final(digest, md5);
	ft_sslprint(digest, MD5_DIGEST_LENGTH);
	ft_mdsha_print_end(md5->opt, msg, file);
	ft_strdel(&msg);
}

void			ft_md5_file(t_mdsha *md5)
{
	t_msg		file;
	uint8_t		digest[MD5_DIGEST_LENGTH];

	read_fd(0, &file);
	if (md5->opt->in)
		ft_printf("%s", file.content);
	ft_md5init(md5);
	ft_md5update(md5, file.content, file.len);
	ft_md5final(digest, md5);
	free(file.content);
	ft_sslprint(digest, MD5_DIGEST_LENGTH);
	ft_printf("\n");
}

void			ft_md5_strings(t_mdsha *md5)
{
	t_msg		*tmp;

	tmp = md5->opt->msg;
	while (tmp != NULL)
	{
		md5_exec(md5, tmp->content, tmp->len, false);
		tmp = tmp->next;
	}
}

int				ft_md5(int ac, char **av)
{
	t_mdsha		md5;
	t_msg		file;
	t_opt		opt;

	opt = get_opt(ac, av);
	md5.opt = &opt;
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
	free_opt(md5.opt);
	return (0);
}
