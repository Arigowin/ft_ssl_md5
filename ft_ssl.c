#include "ft_ssl.h"
#include "ft_md5.h"
#include "ft_sha256.h"
#include "libft.h"
#include "get_next_line.h"

void		usage(char *str)
{
	printf("ft_ssl: Error: '%s' is an invalid command.\n", str);
	printf("\nStandard commands:\n");
	printf("\nMessage Digest commands:\n");
	printf("md5\nsha256\n");
	printf("\nCipher commands:\n");
}

int main(int ac, char **av)
{
	char		*authorized_cmd[2] = {"MD5", "SHA256"};
	int			(*fct[2])(int, char **) = {ft_md5, ft_sha256,};
	int			i;

	if (ac < 2)
	{
		printf("usage: ft_ssl command [command opts] [command args]\n");
		return (1);
	}
	i = 0;
	while (i < 3)
	{
		if (ft_strequ(str_toupper(av[1]), authorized_cmd[i]))
			return (fct[i](ac, av));
		i++;
	}
	usage(av[1]);
	return (1);
}

