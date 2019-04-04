#ifndef FT_SHA256_H
# define FT_SHA256_H

# include "ft_ssl.h"

# define INIT_SHA256_A 0x6a09e667;
# define INIT_SHA256_B 0xbb67ae85;
# define INIT_SHA256_C 0x3c6ef372;
# define INIT_SHA256_D 0xa54ff53a;
# define INIT_SHA256_E 0x510e527f;
# define INIT_SHA256_F 0x9b05688c;
# define INIT_SHA256_G 0x1f83d9ab;
# define INIT_SHA256_H 0x5be0cd19;

uint32_t		get_sha256_k(int i);

int				ft_sha256(int ac, char **av);
void			ft_sha256_body(t_md5sha *sha256, char *imsg);
void			ft_sha256_print_hash(t_md5sha *sha256);

#endif
