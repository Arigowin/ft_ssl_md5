#ifndef FT_MD5_H
# define FT_MD5_H

# include "ft_ssl.h"

# define INIT_MD5_A 0x67452301
# define INIT_MD5_B 0xefcdab89
# define INIT_MD5_C 0x98badcfe
# define INIT_MD5_D 0x10325476

int				get_md5_s(int i);
int				get_md5_k(int i);
char			*md5_opt(t_md5sha *md5, int ac, char **av);
int				md5_padding(uint8_t **msg, char *imsg, size_t ilen);

int				ft_md5(int ac, char **av);
void			ft_md5_body(t_md5sha *md5, char *imsg, size_t ilen);
void			ft_md5_print_hash(t_md5sha *md5);

#endif
