#include "ft_md5.h"
#include "libft.h"

void			md5_opt2(t_md5sha *md5, char **av, int i)
{
	md5->opt.file = true;
	md5->index_file = i;
	md5->av = av;
}

char			*md5_opt(t_md5sha *md5, int ac, char **av)
{
	char		*tmp;
	int			i;

	i = 1;
	tmp = NULL;
	while (++i < ac)
	{
		if (!md5->opt.file && ft_strequ(av[i], "-p"))
			md5->opt.in = true;
		else if (!md5->opt.file && ft_strequ(av[i], "-q"))
			md5->opt.quiet = true;
		else if (!md5->opt.file && ft_strequ(av[i], "-r"))
			md5->opt.reverse = true;
		else if (!md5->opt.file && ft_strequ(av[i], "-s"))
		{
			md5->opt.string = true;
			tmp = ft_strdup(av[++i]);
		}
		else
		{
			md5_opt2(md5, av, i);
			break ;
		}
	}
	return (tmp);
}

int				md5_padding(uint8_t **msg, char *imsg, size_t ilen)
{
	int			new_len;
	uint32_t	bits_len;

	new_len = ilen * 8 + 1;
	while (new_len % 512 != 448)
		new_len++;
	new_len /= 8;
	if ((*msg = (uint8_t *)ft_memalloc(new_len + 64)) == NULL)
		return (-1);
	ft_memcpy(*msg, imsg, ilen);
	(*msg)[ilen] = 0x80;
	bits_len = 8 * ilen;
	ft_memcpy(*msg + new_len, &bits_len, 4);
	return (new_len);
}
