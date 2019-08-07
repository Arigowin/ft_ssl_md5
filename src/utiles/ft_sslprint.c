#include "libft.h"
#include "ft_printf.h"
#include "ft_ssl.h"

void			ft_sslprint(uint8_t *digest, size_t len)
{
	size_t			i;

	i = -1;
	while (++i < len)
		ft_printf("%02x", digest[i]);
}

void			ft_mdsha_print_beg(t_opt *opt, char *algo, char *msg, bool file)
{
	if (opt->reverse == false && opt->quiet == false && file)
		ft_printf("%s (%s) = ", algo, opt->av[opt->index_file]);
	if (opt->reverse == false && opt->quiet == false && !file)
		ft_printf("%s (\"%s\") = ", algo, msg);
}

void			ft_mdsha_print_end(t_opt *opt, char *msg, bool file)
{
	if (opt->reverse && opt->quiet == false && file)
		ft_printf(" %s", opt->av[opt->index_file]);
	else if (opt->reverse && opt->quiet == false && !file)
		ft_printf(" \"%s\"", msg);
	ft_printf("\n");
}
