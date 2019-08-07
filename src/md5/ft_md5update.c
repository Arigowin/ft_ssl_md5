#include "libft.h"
#include "ft_ssl.h"

void	ft_md5update(t_mdsha *md5, const void *imsg, size_t ilen)
{
	const uint8_t	*data;
	size_t			have;
	size_t			need;

	if (ilen <= 0)
		return ;
	data = imsg;
	/* Check how many bytes we already have and how many more we need. */
	have = ((md5->bitlen >> 3) & (MD5_BLOCK_LENGTH - 1));
	need = MD5_BLOCK_LENGTH - have;
	md5->bitlen += ilen << 3;
	if (ilen >= need)
	{
		if (have != 0)
		{
			ft_memcpy(md5->buffer + have, data, need);
			md5transform(md5->parts, md5->buffer);
			data += need;
			ilen -= need;
			have = 0;
		}
		while (ilen >= MD5_BLOCK_LENGTH)
		{
			md5transform(md5->parts, data);
			data += MD5_BLOCK_LENGTH;
			ilen -= MD5_BLOCK_LENGTH;
		}
	}
	if (ilen != 0)
		ft_memcpy(md5->buffer + have, data, ilen);
}
