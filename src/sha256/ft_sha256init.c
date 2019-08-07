#include "libft.h"
#include "ft_ssl.h"

void	ft_sha256init(t_mdsha *sha256)
{
	static uint32_t sha256_initial_hash_value[8] = {
		0x6a09e667UL, 0xbb67ae85UL, 0x3c6ef372UL, 0xa54ff53aUL,
		0x510e527fUL, 0x9b05688cUL, 0x1f83d9abUL, 0x5be0cd19UL
	};

	ft_memcpy(sha256->parts, sha256_initial_hash_value, SHA256_DIGEST_LENGTH);
	ft_memset(sha256->buffer, 0, SHA256_BLOCK_LENGTH);
	sha256->bitlen = 0;
}
