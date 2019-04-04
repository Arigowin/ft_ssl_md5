#ifndef FT_SSL_H
# define FT_SSL_H

#include <stdio.h> // remove

# include <stdbool.h>
# include <stdint.h>

# define LR(x, c) ((x << c) | (x >> (32 - c)))
# define RR(x, c) ((x >> c) | (x << (32 - c)))

typedef struct			s_md5sha_opt
{
	bool				in;
	bool				quiet;
	bool				reverse;
	bool				string;
	bool				file;
}						t_md5sha_opt;

typedef struct			s_md5sha_parts
{
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
}						t_md5sha_parts;

typedef struct			s_md5sha
{
	t_md5sha_opt		opt;
	t_md5sha_parts		parts;
	int					index_file;
	char				**av;
}						t_md5sha;

uint32_t	swap_int32(const uint32_t value);
char		*read_fd(int fd);
char		*read_file(char	*filename);

#endif
