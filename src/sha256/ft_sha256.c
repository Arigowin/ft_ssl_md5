#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"
#include "ft_ssl.h"

void			sha256_exec(t_mdsha *sha256, char *msg, size_t len, bool file)
{
	uint8_t		digest[SHA256_DIGEST_LENGTH];

	if (msg == NULL)
		return ;
	ft_mdsha_print_beg(sha256->opt, "SHA256", msg, file);
	ft_sha256init(sha256);
	ft_sha256update(sha256, msg, len);
	ft_sha256final(digest, sha256);
	ft_sslprint(digest, SHA256_DIGEST_LENGTH);
	ft_mdsha_print_end(sha256->opt, msg, file);
	ft_strdel(&msg);
}

void			ft_sha256_file(t_mdsha *sha256)
{
	t_msg		file;
	uint8_t		digest[SHA256_DIGEST_LENGTH];

	read_fd(0, &file);
	if (sha256->opt->in)
		ft_printf("%s", file.content);
	ft_sha256init(sha256);
	ft_sha256update(sha256, file.content, file.len);
	ft_sha256final(digest, sha256);
	free(file.content);
	ft_sslprint(digest, SHA256_DIGEST_LENGTH);
	ft_printf("\n");
}

void			ft_sha256_strings(t_mdsha *sha256)
{
	t_msg		*tmp;

	tmp = sha256->opt->msg;
	while (tmp != NULL)
	{
		sha256_exec(sha256, tmp->content, tmp->len, false);
		tmp = tmp->next;
	}
}

int				ft_sha256(int ac, char **av)
{
	t_mdsha		sha256;
	t_msg		file;
	t_opt		opt;

	opt = get_opt(ac, av);
	sha256.opt = &opt;
	if ((!sha256.opt->string && !sha256.opt->file) || sha256.opt->in)
		ft_sha256_file(&sha256);
	if (sha256.opt->string)
		ft_sha256_strings(&sha256);
	if (sha256.opt->file)
	{
		while (sha256.opt->index_file < ac)
		{
			if (read_file(sha256.opt->av[sha256.opt->index_file], &file) != NULL)
				sha256_exec(&sha256, file.content, file.len, true);
			sha256.opt->index_file++;
		}
	}
	free_opt(sha256.opt);
	return (0);
}
