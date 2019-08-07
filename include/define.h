#ifndef DEFINE_H
# define DEFINE_H

# define LR(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
# define RR(c, x) (((x) >> (c)) | ((x) << (32 - (c))))
# define Ch(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
# define Maj(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
# define SIG0(x) (RR(7, (x)) ^ RR(18, (x)) ^ ((x) >> 3))
# define SIG1(x) (RR(17, (x)) ^ RR(19, (x)) ^ ((x) >> 10))
# define SIG2(x) (RR(2, (x)) ^ RR(13, (x)) ^ RR(22, (x)))
# define SIG3(x) (RR(6, (x)) ^ RR(11, (x)) ^ RR(25, (x)))

# define MD5_BLOCK_LENGTH			64
# define MD5_DIGEST_LENGTH			16
# define SHA256_BLOCK_LENGTH		64
# define SHA256_DIGEST_LENGTH		32
# define SHA256_SHORT_BLOCK_LENGTH	(SHA256_BLOCK_LENGTH - 8)

#endif
