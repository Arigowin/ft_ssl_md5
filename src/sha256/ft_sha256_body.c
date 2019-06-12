#include <stdlib.h>
#include "ft_sha256.h"
#include "libft.h"
#include "ft_printf.h"

uint32_t		*get_w(uint32_t *msg, int block)
{
	uint32_t	*w;
	int			i;

	if ((w = (uint32_t *)ft_memalloc(64 * sizeof(uint32_t))) == NULL)
		return (0);
	ft_memcpy(w, msg + block * 16, 16 * sizeof(uint32_t));
	i = 15;
	while (++i < 64)
		w[i] = (RR(w[i - 2], 17) ^ RR(w[i - 2], 19) ^ ((w[i - 2]) >> 10))
			+ w[i - 7] + (RR(w[i - 15], 7) ^ RR(w[i - 15], 18)
					^ ((w[i - 15]) >> 3)) + w[i - 16];
	return (w);
}

void			sha256_swap(uint32_t *parts, uint32_t *w, int i)
{
	uint32_t	t1;
	uint32_t	t2;

	t1 = parts[7] + (RR(parts[4], 6) ^ RR(parts[4], 11) ^ RR(parts[4], 25))
		+ ((parts[4] & parts[5]) ^ (~parts[4] & parts[6]))
		+ get_sha256_k(i) + w[i];
	t2 = (RR(parts[0], 2) ^ RR(parts[0], 13) ^ RR(parts[0], 22))
		+ ((parts[0] & parts[1]) ^ (parts[0] & parts[2])
				^ (parts[1] & parts[2]));
	parts[7] = parts[6];
	parts[6] = parts[5];
	parts[5] = parts[4];
	parts[4] = parts[3] + t1;
	parts[3] = parts[2];
	parts[2] = parts[1];
	parts[1] = parts[0];
	parts[0] = t1 + t2;
}

void			sha256_algo(t_mdsha *sha256, uint32_t *w)
{
	uint32_t	parts[8];
	int			i;

	parts[0] = sha256->parts[0];
	parts[1] = sha256->parts[1];
	parts[2] = sha256->parts[2];
	parts[3] = sha256->parts[3];
	parts[4] = sha256->parts[4];
	parts[5] = sha256->parts[5];
	parts[6] = sha256->parts[6];
	parts[7] = sha256->parts[7];
	i = -1;
	while (++i < 64)
		sha256_swap(parts, w, i);
	sha256->parts[0] += parts[0];
	sha256->parts[1] += parts[1];
	sha256->parts[2] += parts[2];
	sha256->parts[3] += parts[3];
	sha256->parts[4] += parts[4];
	sha256->parts[5] += parts[5];
	sha256->parts[6] += parts[6];
	sha256->parts[7] += parts[7];
}

void			ft_sha256_body(t_mdsha *sha256, char *imsg, size_t ilen)
{
	uint32_t	new_len;
	uint32_t	block;
	uint32_t	*msg;
	uint32_t	*w;

	msg = NULL;
	w = NULL;
	if ((new_len = sha256_padding(&msg, imsg, ilen)) == 0)
	{
		ft_printf("ft_ssl: sha256: An error occured\n");
		return ;
	}
	block = 0;
	while (block < (new_len / 64))
	{
		if ((w = get_w(msg, block)) == NULL)
		{
			ft_printf("ft_ssl: sha256: Allocation failes\n");
		}
		sha256_algo(sha256, w);
		free(w);
		block++;
	}
	free(msg);
}
