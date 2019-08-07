#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include <stdint.h>
# include <string.h>
# include "define.h"

typedef struct			s_msg
{
	char				*content;
	size_t				len;
	struct s_msg		*next;;
}						t_msg;

typedef struct			s_opt
{
	bool				in;
	bool				quiet;
	bool				reverse;
	bool				string;
	t_msg				*msg;
	bool				file;
	int					index_file;
	char				**av;
}						t_opt;

typedef struct			s_mdsha
{
	t_opt				*opt;
	int					index_file;
	char				**av;
	uint32_t			parts[8];
	uint64_t			bitlen;
	uint8_t				buffer[SHA256_BLOCK_LENGTH];
}						t_mdsha;

typedef struct			s_algo
{
	char				*name;
	char				*full_name;
	int					(*algo)(int, char **);
}						t_algo;

#endif
