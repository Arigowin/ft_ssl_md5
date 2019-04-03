#include "ft_ssl.h"
#include "ft_md5.h"
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
	if (ac < 2)
	{
		printf("usage: ft_ssl command [command opts] [command args]\n");
		return (1);
	}
	if (ft_strcmp(av[1], "md5") == 0)
		ft_md5(ac, av);
	else
		usage(av[1]);
	return (0);
}

