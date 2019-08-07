.PHONY: all clean fclean re

CC =		/usr/bin/clang
MAKE =		/usr/bin/make
RM =		/bin/rm
MKDIR = 	/bin/mkdir

NAME = ft_ssl

ROOT =				$(shell /bin/pwd)
OPATH =				$(ROOT)/obj/
CPATH =				$(ROOT)/src/
HPATH =				$(ROOT)/include/
LIBPATH =			$(ROOT)/libft
LIBHPATH =			$(LIBPATH)/includes
LIBPRINTFPATH =		$(ROOT)/ft_printf
LIBPRINTFHPATH =	$(LIBPRINTFPATH)/include

CFLAGS = -Wall -Wextra -Werror -I $(HPATH) -I $(LIBHPATH) -I $(LIBPRINTFHPATH) -g
LIBS = -L $(LIBPATH) -lft -L$(LIBPRINTFPATH) -lftprintf

SRC = ft_ssl.c \
	  utiles/opt.c \
	  utiles/opt_more.c \
	  utiles/utiles.c \
	  utiles/ft_sslprint.c \
	  \
	  md5/ft_md5.c \
	  md5/ft_md5final.c \
	  md5/ft_md5init.c \
	  md5/ft_md5transform.c \
	  md5/ft_md5update.c \
	  \
	  sha256/ft_sha256.c \
	  sha256/ft_sha256final.c \
	  sha256/ft_sha256init.c \
	  sha256/ft_sha256transform.c \
	  sha256/ft_sha256update.c

SRCS = $(addprefix $(CPATH), $(SRC_ALL))

OBJ = $(SRC:.c=.o)
	OBJS = $(addprefix $(OPATH), $(OBJ))

INC = ft_ssl.h \
	  struct.h \
	  define.h

INCS = $(addprefix $(HPATH), $(INC))

all: $(NAME)

$(NAME): $(OPATH) $(OBJS)
	@make -C $(LIBPATH)
	@make -C $(LIBPRINTFPATH)
	@echo "Creating OBJ files"
	@echo "Building $@"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
	@echo "\033[36mAll is done!\033[0m"

$(OPATH)%.o: $(CPATH)%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@mkdir -p $(OPATH)
	@mkdir -p $(OPATH)/md5
	@mkdir -p $(OPATH)/sha256
	@mkdir -p $(OPATH)/utiles

clean:
	@echo "Deleting OBJ files"
	@make clean -C $(LIBPATH)
	@make clean -C $(LIBPRINTFPATH)
	@rm -f $(OBJS)
	@rm -rf $(OPATH)

fclean: clean
	@echo "Deleting $(NAME)"
	@make fclean -C $(LIBPATH)
	@make fclean -C $(LIBPRINTFPATH)
	@rm -f $(NAME)
	@echo "\033[36mAll clear!\033[0m"

re: fclean all

