#include "ft_ssl.h"

void	ft_md5final(uint8_t digest[MD5_DIGEST_LENGTH], t_mdsha *md5)
{
	static uint8_t padding[MD5_BLOCK_LENGTH] = {
	    0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint8_t	bitlen[8];
	size_t	pad;
	int		i;

	// convert to little endian
	bitlen[7] = (md5->bitlen) >> 56;
	bitlen[6] = (md5->bitlen) >> 48;
	bitlen[5] = (md5->bitlen) >> 40;
	bitlen[4] = (md5->bitlen) >> 32;
	bitlen[3] = (md5->bitlen) >> 24;
	bitlen[2] = (md5->bitlen) >> 16;
	bitlen[1] = (md5->bitlen) >> 8;
	bitlen[0] = (md5->bitlen);

	pad = MD5_BLOCK_LENGTH - ((md5->bitlen >> 3) & (MD5_BLOCK_LENGTH - 1));
	if (pad < 9)
		pad += MD5_BLOCK_LENGTH;
	ft_md5update(md5, padding, pad - 8);
	ft_md5update(md5, bitlen, 8);

	i = 0;
	while (i < 4)
	{
		(digest + i * 4)[3] = (md5->parts[i]) >> 24;
		(digest + i * 4)[2] = (md5->parts[i]) >> 16;
		(digest + i * 4)[1] = (md5->parts[i]) >> 8;
		(digest + i * 4)[0] = (md5->parts[i]);
		i++;
	}
}
