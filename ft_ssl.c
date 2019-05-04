#include "ft_ssl.h"
#include "ft_md5.h"
#include "ft_sha256.h"
#include "libft.h"
#include "ft_printf.h"
#include "get_next_line.h"

void		usage(char *str)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n", str);
	ft_printf("\nStandard commands:\n");
	ft_printf("\nMessage Digest commands:\n");
	ft_printf("md5\nsha256\n");
	ft_printf("\nCipher commands:\n");
}

int			main(int ac, char **av)
{
	static char	*authorized_cmd[2] = {"MD5", "SHA256"};
	static int	(*fct[2])(int, char **) = {ft_md5, ft_sha256};
	int			i;

	if (ac < 2)
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		return (1);
	}
	i = 0;
	while (i < 2)
	{
		if (ft_strequ(str_toupper(av[1]), authorized_cmd[i]))
			return (fct[i](ac, av));
		i++;
	}
	usage(av[1]);
	return (1);
}
