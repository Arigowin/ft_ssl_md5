#include "ft_md5.h"
#include "libft.h"

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
