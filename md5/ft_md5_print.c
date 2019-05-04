#include "ft_md5.h"
#include "ft_printf.h"

void			ft_md5_print_hash(t_md5sha *md5)
{
	uint8_t		*ptr;

	ptr = (uint8_t *)&(md5->parts.a);
	ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&(md5->parts.b);
	ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&(md5->parts.c);
	ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&(md5->parts.d);
	ft_printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
}
