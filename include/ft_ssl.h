#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdbool.h>
# include <stdint.h>
# include <string.h>

# define LR(x, c) ((x << c) | (x >> (32 - c)))
# define RR(x, c) ((x >> c) | (x << (32 - c)))

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
	uint32_t			parts[8];
}						t_mdsha;

typedef struct			s_algo
{
	char				*name;
	char				*full_name;
	int					(*algo)(t_opt *, int);
}						t_algo;

uint32_t				swap_int32(const uint32_t value);
char					*read_fd(int fd, t_msg *file);
char					*read_file(char	*filename, t_msg *file);
t_opt					get_opt(int ac, char **av);
void					free_opt(t_opt *opt);
void					add_msg(t_opt *opt, char *msg);
void					opt_more(t_opt *opt, char **av, int i);
void					opt_s(t_opt *opt, char **av, int *i, size_t j);

#endif
