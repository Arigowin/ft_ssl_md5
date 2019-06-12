#include <stdlib.h>
#include "ft_ssl.h"
#include "ft_md5.h"
#include "ft_sha256.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

static t_algo	g_algo[3] = {
	{"md5", "MD5", ft_md5},
	{"sha256", "SHA256", ft_sha256},
	{NULL, NULL, NULL}
};

int			usage1(void)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
	return (1);
}

int			usage2(char *str)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", str);
	ft_printf("\nStandard commands:\n");
	ft_printf("\nMessage Digest commands:\n");
	ft_printf("md5\nsha256\n");
	ft_printf("\nCipher commands:\n");
	return (1);
}

int			main(int ac, char **av)
{
	t_opt		opt;
	int			ret;
	int			i;

	if (ac < 2)
		return (usage1());
	i = -1;
	while (++i < 2)
	{
		if (ft_strequ(av[1], g_algo[i].name)
				|| ft_strequ(av[1], g_algo[i].full_name))
		{
			opt = get_opt(ac, av);
			ret = g_algo[i].algo(&opt, ac);
			free_opt(&opt);
			return (ret);
		}
	}
	return (usage2(av[1]));
}
