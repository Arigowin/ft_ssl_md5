CC =		/usr/bin/clang
MAKE =		/usr/bin/make
RM =		/bin/rm
MKDIR = 	/bin/mkdir

NAME = ft_ssl

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/obj
CPATH =		$(ROOT)/src
HPATH =		$(ROOT)/include
LIBPATH =	$(ROOT)/libft
LIBHPATH =	$(LIBPATH)/includes
MD5_DIR = 	$(ROOT)/md5

CFLAGS = -Wall -Wextra -Werror -I $(HPATH) -I $(LIBHPATH) -g
LIBS = -L $(LIBPATH) -lft

_DEPS = ft_ssl.h ft_md5.h
DEPS = $(patsubst %,$(HPATH)/%,$(_DEPS))

SRC = ft_ssl.c utiles.c
MD5_SRC = ft_md5_print.c ft_md5_global.c ft_md5_body.c ft_md5.c 

MD5 = $(patsubst %, $(MD5_DIR)/%, $(MD5_SRC))

SRC_OBJ =$(SRC:.c=.o)
MD5_OBJ = $(MD5:.c=.o)
OBJ = $(SRC_OBJ) $(MD5_OBJ)

all: $(NAME)

%.o: %.c $(DEPS)
	@$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBPATH) -j 8
	@echo "Creating OBJ files"
	@echo "Building $@"
	@$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	@echo "\033[36mAll is done!\033[0m"

md5: $(MD5_OBJ)
	@$(CC) -o ft_ssl_$@ $^ $(CFLAGS) $(LIBS)

lib.clean:
	@$(MAKE) clean -C $(LIBPATH)

clean: lib.clean
	@echo "Deleting OBJ files"
	@$(RM) -f $(OBJ)

lib.fclean:
	@$(MAKE) fclean -C $(LIBPATH)

fclean: clean lib.fclean
	@echo "Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\033[36mAll clear!\033[0m"

re: fclean all

.PHONY: clean fclean re

