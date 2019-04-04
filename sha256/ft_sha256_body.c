#include <stdlib.h>
#include "ft_sha256.h"
#include "libft.h"

int			add_padlen(uint32_t *buff, int ilen)
{
	size_t          size;
	uint32_t        inp_bitlen;
	size_t          num_blocks;
	int             i;

	inp_bitlen = 8 * ilen;
	size = inp_bitlen + 64;
	while (++size % 512)
		;
	num_blocks = size / 512;
	size % 512 ? num_blocks++ : 1;
	((char*)buff)[ilen] = 0x80;
	i = -1;
	while (++i < (int)(num_blocks * 16) - 1)
		buff[i] = swap_int32(buff[i]);
	buff[((num_blocks * 512 - 64) / 32) + 1] = inp_bitlen;
	return (num_blocks * 64);
}

int				sha256_padding(char *imsg, uint8_t **msg)
{
	uint32_t	new_len;
	int			ilen;

	ilen = ft_strlen(imsg);
	new_len = ilen + 9;
	while ((new_len * 8) % 512)
		new_len++;
	if ((*msg = (uint8_t *)malloc(new_len)) == NULL)
		return (-1);
	ft_bzero(*msg, new_len);
	ft_memcpy(*msg, imsg, ilen);
	new_len = add_padlen((uint32_t *)(*msg), ilen);
	return (new_len);
}

uint32_t		*get_w(uint8_t *msg, int block)
{
	uint32_t	*w;
	int			i;

	if ((w = (uint32_t *)malloc(64 * sizeof(uint32_t))) == NULL)
		return (0);
	bzero(w, 64 * sizeof(uint32_t));
	ft_memcpy(w, msg + block * 16, 16 * sizeof(uint32_t));
	i = 15;
	while (++i < 64)
		w[i] = (RR(w[i - 2],17) ^ RR(w[i - 2],19) ^ ((w[i - 2]) >> 10))
			+ w[i - 7] + (RR(w[i - 15],7) ^ RR(w[i - 15],18)
					^ ((w[i - 15]) >> 3)) + w[i - 16];
	return (w);
}

void			sha256_swap(uint32_t *parts, uint32_t *w, int i)
{
	uint32_t	t1;
	uint32_t	t2;

	t1 = parts[7] + (RR(parts[4], 6) ^ RR(parts[4], 11) ^ RR(parts[4], 25))
		+ ((parts[4] & parts[5]) ^ (~parts[4] & parts[6])) + get_sha256_k(i) + w[i];
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

void			sha256_algo(t_md5sha *sha256, uint32_t *w)
{
	uint32_t	parts[8];
	int			i;

	parts[0] = sha256->parts.a;
	parts[1] = sha256->parts.b;
	parts[2] = sha256->parts.c;
	parts[3] = sha256->parts.d;
	parts[4] = sha256->parts.e;
	parts[5] = sha256->parts.f;
	parts[6] = sha256->parts.g;
	parts[7] = sha256->parts.h;
	i = -1;
	while (++i < 64)
		sha256_swap(parts, w, i);
	sha256->parts.a += parts[0];
	sha256->parts.b += parts[1];
	sha256->parts.c += parts[2];
	sha256->parts.d += parts[3];
	sha256->parts.e += parts[4];
	sha256->parts.f += parts[5];
	sha256->parts.g += parts[6];
	sha256->parts.h += parts[7];
}

void			ft_sha256_body(t_md5sha *sha256, char *imsg)
{
	uint32_t	new_len;
	uint32_t	block;
	uint8_t		*msg;
	uint32_t	*w;

	msg = NULL;
	w = NULL;
	if ((new_len = sha256_padding(imsg, &msg)) == 0)
	{
		printf("ft_ssl: sha256: An error occured\n");
		return ;
	}
	block = 0;
	while (block < (new_len / 64))
	{
		if ((w = get_w(msg, block)) == NULL)
		{
			printf("ft_ssl: sha256: Allocation failes\n");
		}
		sha256_algo(sha256, w);
		block++;
	}
	free(msg);
}
