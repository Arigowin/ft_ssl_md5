#include "ft_sha256.h"
#include "libft.h"
#include "ft_printf.h"

void			ft_sha256_print_hash(t_mdsha *sha256)
{
	uint8_t		hash[32];
	int			i;

	ft_bzero(hash, sizeof(uint8_t) * 32);
	i = -1;
	while (++i < 4)
	{
		hash[i] = (sha256->parts[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4] = (sha256->parts[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8] = (sha256->parts[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (sha256->parts[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (sha256->parts[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (sha256->parts[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (sha256->parts[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (sha256->parts[7] >> (24 - i * 8)) & 0x000000ff;
	}
	i = -1;
	while (++i < 32)
		ft_printf("%02x", hash[i]);
}
