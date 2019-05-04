#include "ft_sha256.h"
#include "libft.h"

void			sha256_opt2(t_md5sha *sha256, char **av, int i)
{
	sha256->opt.file = true;
	sha256->index_file = i;
	sha256->av = av;
}

char			*sha256_opt(t_md5sha *sha256, int ac, char **av)
{
	char		*tmp;
	int			i;

	i = 1;
	tmp = NULL;
	while (++i < ac)
	{
		if (!sha256->opt.file && ft_strequ(av[i], "-p"))
			sha256->opt.in = true;
		else if (!sha256->opt.file && ft_strequ(av[i], "-q"))
			sha256->opt.quiet = true;
		else if (!sha256->opt.file && ft_strequ(av[i], "-r"))
			sha256->opt.reverse = true;
		else if (!sha256->opt.file && ft_strequ(av[i], "-s"))
		{
			sha256->opt.string = true;
			tmp = ft_strdup(av[++i]);
		}
		else
		{
			sha256_opt2(sha256, av, i);
			break ;
		}
	}
	return (tmp);
}

int				add_padlen(uint32_t *buff, int ilen)
{
	size_t			size;
	uint32_t		inp_bitlen;
	size_t			num_blocks;
	int				i;

	inp_bitlen = 8 * ilen;
	size = inp_bitlen + 64;
	while (++size % 512)
		;
	num_blocks = size / 512;
	size % 512 ? num_blocks++ : 1;
	((char*)buff)[ilen] = 0x80;
	i = -1;
	while (++i < (int)(num_blocks * 16) - 1)
		buff[i] = swap_int32(buff[i]);
	buff[((num_blocks * 512 - 64) / 32) + 1] = inp_bitlen;
	return (num_blocks * 64);
}

int				sha256_padding(uint32_t **msg, char *imsg, size_t ilen)
{
	uint32_t	new_len;

	new_len = ilen + 9;
	while ((new_len * 8) % 512)
		new_len++;
	if ((*msg = (uint32_t *)ft_memalloc(new_len)) == NULL)
		return (-1);
	ft_memcpy(*msg, imsg, ilen);
	new_len = add_padlen((uint32_t *)(*msg), ilen);
	return (new_len);
}
