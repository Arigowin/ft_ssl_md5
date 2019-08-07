#ifndef FT_SSL_H
# define FT_SSL_H

# include "struct.h"
# include "define.h"

/* ft_ssl */
uint32_t	swap32(uint32_t a);
uint64_t 	swap64(uint64_t a);
char		*read_fd(int fd, t_msg *file);
char		*read_file(char	*filename, t_msg *file);
t_opt		get_opt(int ac, char **av);
void		free_opt(t_opt *opt);
void		add_msg(t_opt *opt, char *msg);
void		opt_more(t_opt *opt, char **av, int i);
void		opt_s(t_opt *opt, char **av, int *i, size_t j);
void		ft_sslprint(uint8_t *digest, size_t len);
void		ft_mdsha_print_beg(t_opt *opt, char *algo, char *msg, bool file);
void		ft_mdsha_print_end(t_opt *opt, char *msg, bool file);

/* ft_md5 */
int			ft_md5(int ac, char **av);
void		ft_md5init(t_mdsha *md5);
void		ft_md5update(t_mdsha *md5, const void *imsg, size_t len);
void		ft_md5final(uint8_t digest[MD5_DIGEST_LENGTH], t_mdsha *md5);
void		md5transform(uint32_t iparts[4], const uint8_t block[MD5_BLOCK_LENGTH]);

/* ft_sha256 */
int			ft_sha256(int ac, char **av);
void		ft_sha256init(t_mdsha *sha256);
void		ft_sha256update(t_mdsha *sha256, const void *imsg, size_t ilen);
void		ft_sha256final(uint8_t digest[SHA256_DIGEST_LENGTH], t_mdsha *sh);
void		sha256transform(uint32_t *iparts, const uint8_t *data);

#endif
