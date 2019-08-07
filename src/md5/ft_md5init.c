#include "ft_ssl.h"

void	ft_md5init(t_mdsha *md5)
{
	md5->bitlen = 0;
	md5->parts[0] = 0x67452301;
	md5->parts[1] = 0xefcdab89;
	md5->parts[2] = 0x98badcfe;
	md5->parts[3] = 0x10325476;
}
