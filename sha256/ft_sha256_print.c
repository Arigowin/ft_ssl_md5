#include "ft_sha256.h"
#include "libft.h"
#include "ft_printf.h"

void			ft_sha256_print_hash(t_md5sha *sha256)
{
	uint8_t hash[32];
	int i;

	ft_bzero(hash, sizeof(uint8_t) * 32);
	i = -1;
	while (++i < 4)
	{
		hash[i] = 		(sha256->parts.a >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4] = 	(sha256->parts.b >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8] = 	(sha256->parts.c >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = 	(sha256->parts.d >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = 	(sha256->parts.e >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = 	(sha256->parts.f >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = 	(sha256->parts.g >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = 	(sha256->parts.h >> (24 - i * 8)) & 0x000000ff;
	}
	i = -1;
	while (++i < 32)
		ft_printf("%02x", hash[i]);
}
