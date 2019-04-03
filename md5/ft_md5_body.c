#include "libft.h"
#include "ft_md5.h"

int				padding_msg(t_md5 *md5, uint8_t **msg)
{
	int			new_len;
	uint32_t	bits_len;

	new_len = md5->initial_len * 8 + 1;
	while (new_len % 512 < 448)
		new_len++;
	new_len /= 8;
	if ((*msg = (uint8_t *)malloc(new_len + 64)) == NULL)
		return (-1);
	ft_bzero(*msg, new_len + 64);
	ft_memcpy(*msg, md5->initial_message, md5->initial_len);
	(*msg)[md5->initial_len] = 128;
	bits_len = 8 * md5->initial_len;
	ft_memcpy(*msg + new_len, &bits_len, 4);
	return (new_len);
}

void			md5_swap(uint32_t *parts, uint32_t x)
{
	uint32_t	tmp;

	tmp = parts[3];
	parts[3] = parts[2];
	parts[2] = parts[1];
	parts[1] = parts[1] + x;
	parts[0] = tmp;
}

void			md5_algo(t_md5 *md5, uint32_t *w)
{
	uint32_t	parts[4];
	uint32_t	f;
	uint32_t	g;
	uint32_t	i;

	parts[0] = md5->parts.a;
	parts[1] = md5->parts.b;
	parts[2] = md5->parts.c;
	parts[3] = md5->parts.d;
	i = -1;
	while (++i < 64)
	{
		f = (i < 16 ? ((parts[1] & parts[2]) | (~parts[1] & parts[3]))
				: (i < 32 ? ((parts[3] & parts[1]) | (~parts[3] & parts[2]))
					: (i < 48 ? (parts[1] ^ parts[2] ^ parts[3])
						: (parts[2] ^ (parts[1] | ~parts[3])))));
		g = (i < 16 ? i : (i < 32 ? (5 * i + 1) % 16
					: (i < 48 ? (3 * i + 5) % 16 : (7 * i) % 16)));
		md5_swap(parts, LEFTROTATE((parts[0] + f + g_k[i] + w[g]), g_s[i]));
	}
	md5->parts.a += parts[0];
	md5->parts.b += parts[1];
	md5->parts.c += parts[2];
	md5->parts.d += parts[3];
}

void			ft_md5_body(t_md5 *md5)
{
	int			new_len;
	int			block;
	uint8_t		*msg;
	uint32_t	*w;

	msg = NULL;
	if ((new_len = padding_msg(md5, &msg)) == -1)
		return ; // ERROR
	block = 0;
	while (block < new_len)
	{
		w = (uint32_t *)(msg + block);
		md5_algo(md5, w);
		block += 512 / 8;
	}
	free(msg);
}
