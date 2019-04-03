#include "ft_md5.h"

void			ft_md5_print_hash(t_md5 *md5)
{
	uint8_t		*ptr;

	ptr = (uint8_t *)&(md5->parts.a);
	printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&(md5->parts.b);
	printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&(md5->parts.c);
	printf("%2.2x%2.2x%2.2x%2.2x", ptr[0], ptr[1], ptr[2], ptr[3]);
	ptr = (uint8_t *)&(md5->parts.d);
	printf("%2.2x%2.2x%2.2x%2.2x\n", ptr[0], ptr[1], ptr[2], ptr[3]);
}
