CC =		/usr/bin/clang
MAKE =		/usr/bin/make
RM =		/bin/rm
MKDIR = 	/bin/mkdir

NAME = ft_ssl

ROOT =				$(shell /bin/pwd)
OPATH =				$(ROOT)/obj
CPATH =				$(ROOT)/src
HPATH =				$(ROOT)/include
LIBPATH =			$(ROOT)/libft
LIBHPATH =			$(LIBPATH)/includes
LIBPRINTFPATH =		$(ROOT)/ft_printf
LIBPRINTFHPATH =	$(LIBPRINTFPATH)/include
MD5_DIR = 			$(ROOT)/md5
SHA256_DIR = 		$(ROOT)/sha256

CFLAGS = -Wall -Wextra -Werror -I $(HPATH) -I $(LIBHPATH) -I $(LIBPRINTFHPATH) -g
LIBS = -L $(LIBPATH) -lft -L$(LIBPRINTFPATH) -lftprintf

_DEPS = ft_ssl.h ft_md5.h ft_sha256.h
DEPS = $(patsubst %,$(HPATH)/%,$(_DEPS))

SRC = ft_ssl.c utiles.c
MD5_SRC = ft_md5_print.c ft_md5_global.c ft_md5_body.c ft_md5.c 
SHA256_SRC = ft_sha256_print.c ft_sha256_global.c ft_sha256_body.c ft_sha256.c 

MD5 = $(patsubst %, $(MD5_DIR)/%, $(MD5_SRC))
SHA256 = $(patsubst %, $(SHA256_DIR)/%, $(SHA256_SRC))

SRC_OBJ =$(SRC:.c=.o)
MD5_OBJ = $(MD5:.c=.o)
SHA256_OBJ = $(SHA256:.c=.o)
OBJ = $(SRC_OBJ) $(MD5_OBJ) $(SHA256_OBJ)

all: $(NAME)

%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBPATH) -j 8
	@$(MAKE) -C $(LIBPRINTFPATH) -j 8
	@echo "Creating OBJ files"
	@echo "Building $@"
	@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[36mAll is done!\033[0m"


sha256: $(SHA256_OBJ)
	$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)

md5: $(MD5_OBJ)
	@$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)

lib.clean:
	@$(MAKE) clean -C $(LIBPATH)
	@$(MAKE) clean -C $(LIBPRINTFPATH)

clean: lib.clean
	@echo "Deleting OBJ files"
	@$(RM) -f $(OBJ)

lib.fclean:
	@$(MAKE) fclean -C $(LIBPATH)
	@$(MAKE) fclean -C $(LIBPRINTFPATH)

fclean: clean lib.fclean
	@echo "Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\033[36mAll clear!\033[0m"

re: fclean all

.PHONY: clean fclean re

