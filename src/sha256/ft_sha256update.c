#include "libft.h"
#include "ft_ssl.h"

int		sha256recall(t_mdsha *sha256, const uint8_t *data,
		size_t *ilen)
{
	// used, free
	size_t				space[2];

	space[0] = (sha256->bitlen >> 3) % SHA256_BLOCK_LENGTH;
	if (space[0] > 0)
	{
		space[1] = SHA256_BLOCK_LENGTH - space[0];
		if (*ilen >= space[1])
		{
			ft_memcpy(&(sha256->buffer[space[0]]), data, space[1]);
			sha256->bitlen += space[1] << 3;
			*ilen -= space[1];
			data += space[1];
			sha256transform(sha256->parts, sha256->buffer);
		}
		else
		{
			ft_memcpy(&(sha256->buffer[space[0]]), data, *ilen);
			sha256->bitlen += *ilen << 3;
			return (1);
		}
	}
	return (0);
}

void	ft_sha256update(t_mdsha *sha256, const void *imsg, size_t ilen)
{
	const uint8_t		*data;

	if (ilen <= 0)
		return ;
	data = imsg;
	// if we used multiple update without call sha256init()
	sha256recall(sha256, data, &ilen);
	while (ilen >= SHA256_BLOCK_LENGTH)
	{
		sha256transform(sha256->parts, data);
		sha256->bitlen += SHA256_BLOCK_LENGTH << 3;
		ilen -= SHA256_BLOCK_LENGTH;
		data += SHA256_BLOCK_LENGTH;
	}
	if (ilen > 0)
	{
		ft_memcpy(sha256->buffer, data, ilen);
		sha256->bitlen += ilen << 3;
	}
}
