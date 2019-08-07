#include "libft.h"
#include "ft_ssl.h"

void	ft_sha256padding(t_mdsha *sha256)
{
	unsigned int usedspace;

	// bitlen >> 3 for retrieve the initial length
	usedspace = (sha256->bitlen >> 3) % SHA256_BLOCK_LENGTH;
	if (usedspace > 0)
	{
		sha256->buffer[usedspace++] = 0x80;
		if (usedspace <= SHA256_SHORT_BLOCK_LENGTH)
			ft_memset(&(sha256->buffer[usedspace]), 0,
					SHA256_SHORT_BLOCK_LENGTH - usedspace);
		else
		{
			if (usedspace < SHA256_BLOCK_LENGTH)
				ft_memset(&(sha256->buffer[usedspace]), 0,
						SHA256_BLOCK_LENGTH - usedspace);
			sha256transform(sha256->parts, sha256->buffer);
			ft_memset(sha256->buffer, 0, SHA256_SHORT_BLOCK_LENGTH);
		}
	}
	else
	{
		ft_memset(sha256->buffer, 0, SHA256_SHORT_BLOCK_LENGTH);
		*(sha256->buffer) = 0x80;
	}
}

void	ft_sha256final(uint8_t digest[], t_mdsha *sha256)
{
	int		i;

	ft_sha256padding(sha256);
	sha256->bitlen = swap64(sha256->bitlen);
	*(uint64_t*)(&(sha256->buffer[SHA256_SHORT_BLOCK_LENGTH])) = sha256->bitlen;
	sha256transform(sha256->parts, sha256->buffer);
	i = 0;
	while (i < 8)
	{
		sha256->parts[i] = swap32(sha256->parts[i]);
		i++;
	}
	ft_memcpy(digest, sha256->parts, SHA256_DIGEST_LENGTH);
}
