#ifndef FT_MD5_H
# define FT_MD5_H
#include <stdio.h> // remove

# include <stdlib.h>
# include <sys/types.h>
# include <stdbool.h>
# include <stdint.h>

# define NAME "ft_ssl: md5:"
# define INIT_A 0x67452301
# define INIT_B 0xefcdab89
# define INIT_C 0x98badcfe
# define INIT_D 0x10325476
# define LEFTROTATE(x, c) ((x << c) | (x >> (32 - c)))

extern int g_s[64];
extern int g_k[64];

typedef unsigned int	t_uint;

typedef struct			s_md5_opt
{
	bool				in;
	bool				quiet;
	bool				reverse;
	bool				string;
	bool				file;
}						t_md5_opt;

typedef struct			s_md5_parts
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
}						t_md5_parts;

typedef struct			s_md5
{
	t_md5_opt			opt;
	int					index_file;
	char				**av;
	t_md5_parts			parts;
}						t_md5;

int				ft_md5(int ac, char **av);
void			ft_md5_body(t_md5 *md5, char *msg);
void			ft_md5_print_hash(t_md5 *md5);

#endif
