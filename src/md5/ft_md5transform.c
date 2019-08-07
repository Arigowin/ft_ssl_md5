#include "libft.h"
#include "ft_ssl.h"

int		md5gets(int i)
{
	int		s[64] = {
		7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
		5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4,
		11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6,
		10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21
	};
	return (s[i]);
}

int		md5getk(int i)
{
	int		k[64] = {
		0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
		0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
		0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
		0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
		0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
		0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
		0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
		0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
		0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
		0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
		0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
		0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
		0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
		0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
		0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
		0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
	};
	return (k[i]);
}

void			md5initlocalparts(uint32_t (*p)[], uint32_t *ip)
{
	(*p)[0] = ip[0];
	(*p)[1] = ip[1];
	(*p)[2] = ip[2];
	(*p)[3] = ip[3];
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

void	md5transform(uint32_t iparts[4], const uint8_t block[MD5_BLOCK_LENGTH])
{
	uint32_t	p[4];
	uint32_t	in[MD5_DIGEST_LENGTH];
	uint32_t	f;
	uint32_t	g;
	int			i;

	ft_memcpy(in, block, sizeof(in));
	md5initlocalparts(&p, iparts);
	i = -1;
	while (++i < 64)
	{
		f = (i < 16 ? ((p[1] & p[2]) | (~p[1] & p[3]))
				: (i < 32 ? ((p[3] & p[1]) | (~p[3] & p[2]))
					: (i < 48 ? (p[1] ^ p[2] ^ p[3])
						: (p[2] ^ (p[1] | ~p[3])))));
		g = (i < 16 ? i : (i < 32 ? (5 * i + 1) % 16
					: (i < 48 ? (3 * i + 5) % 16 : (7 * i) % 16)));
		md5_swap(p, LR((p[0] + f + md5getk(i) + in[g]), md5gets(i)));
	}
	iparts[0] += p[0];
	iparts[1] += p[1];
	iparts[2] += p[2];
	iparts[3] += p[3];
}

