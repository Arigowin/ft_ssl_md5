#include <stdlib.h>
#include "libft.h"
#include "ft_md5.h"
#include "ft_printf.h"

void			md5_swap(uint32_t *parts, uint32_t x)
{
	uint32_t	tmp;

	tmp = parts[3];
	parts[3] = parts[2];
	parts[2] = parts[1];
	parts[1] = parts[1] + x;
	parts[0] = tmp;
}

uint32_t		get_f(uint32_t p[], uint32_t i)
{
	uint32_t	f;

	f = 0;
	f = (i < 16 ? ((p[1] & p[2]) | (~p[1] & p[3])) : f);
	f = (i >= 16 && i < 32 ? ((p[3] & p[1]) | (~p[3] & p[2])) : f);
	f = (i >= 32 && i < 48 ? (p[1] ^ p[2] ^ p[3]) : f);
	f = (i >= 48 ? (p[2] ^ (p[1] | ~p[3])) : f);
	return (f);
}

uint32_t		get_g(uint32_t i)
{
	uint32_t	g;

	g = 0;
	g = (i < 16 ? i : g);
	g = (i >= 16 && i < 32 ? (5 * i + 1) % 16 : g);
	g = (i >= 32 && i < 48 ? (3 * i + 5) % 16 : g);
	g = (i >= 48 ? (7 * i) % 16 : g);
	return (g);
}

void			md5_algo(t_md5sha *md5, uint32_t *w)
{
	uint32_t	p[4];
	uint32_t	i;

	p[0] = md5->parts.a;
	p[1] = md5->parts.b;
	p[2] = md5->parts.c;
	p[3] = md5->parts.d;
	i = -1;
	while (++i < 64)
	{
		md5_swap(p, LR((p[0] + get_f(p, i) + get_md5_k(i) + w[get_g(i)]),
					get_md5_s(i)));
	}
	md5->parts.a += p[0];
	md5->parts.b += p[1];
	md5->parts.c += p[2];
	md5->parts.d += p[3];
}

void			ft_md5_body(t_md5sha *md5, char *imsg, size_t ilen)
{
	int			new_len;
	int			block;
	uint8_t		*msg;

	msg = NULL;
	if ((new_len = md5_padding(&msg, imsg, ilen)) == -1)
	{
		ft_printf("ft_ssl: md5: Allocation failed\n");
		return ;
	}
	block = 0;
	while (block < new_len)
	{
		md5_algo(md5, (uint32_t *)(msg + block));
		block += (512 / 8);
	}
	free(msg);
}
