#include "ft_md5.h"
#include "ft_printf.h"

void			ft_md5_print_hash(t_mdsha *md5)
{
	uint8_t		*ptr;
	int			i;

	i = 0;
	while (i < 4)
	{
		ptr = (uint8_t *)&(md5->parts[i]);
		ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
		i++;
	}
}
