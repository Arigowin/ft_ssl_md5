CC =		/usr/bin/clang
RM =		/bin/rm
MAKE =		/usr/bin/make
MKDIR =		/bin/mkdir
AR =		/usr/bin/ar
RANLIB = 	/usr/bin/ranlib

NAME =		libftprintf.a

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/obj
CPATH =		$(ROOT)/src
HPATH =		$(ROOT)/include

CFLAGS = -Wall -Wextra -Werror -I $(HPATH) -fPIC

SRC =	ft_strlen.c \
		ft_nbrlen.c \
		ft_strncount.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strdel.c \
		ft_strstr.c \
		ft_strcmp.c \
		ft_bzero.c \
		ft_memalloc.c \
		ft_strnew.c \
		ft_itoa_base.c \
		ft_atoi.c \
		ft_strcat.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_toupper.c \
		ft_isdigit.c \
		ft_ptr_to_hex.c \
		ft_putchar.c \
		ft_putendl.c \
		ft_putnbrendl.c \
		ft_putstr.c \
		ft_putupper.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_print_n_char.c \
		ft_add_n_char.c \
		ft_add_char_front.c \
		ft_add_char_back.c \
		ft_remove_char.c \
		ft_prntnum.c \
		chaining_list.c \
		parsing.c \
		parsing2.c \
		ft_add_char.c \
		ft_add_symbole.c \
		no_conv.c \
		other_conv.c \
		conv_pct.c \
		conv_s.c \
		conv_d.c \
		conv_c.c \
		conv_p.c \
		conv_o.c \
		conv_o2.c \
		conv_u.c \
		conv_x.c \
		conv_f.c \
		conv_f2.c \
		conversion_manager.c \
		print_all.c \
		ft_printf.c

OBJ = $(patsubst %.c, $(OPATH)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OPATH) $(NAME)

$(NAME): $(OPATH) $(OBJ)
	@echo "$(NAME) : Building $@"
	@$(AR) rc $@ $(OBJ)
	@$(RANLIB) $@
	@echo "\033[32mDone !\033[0m"

$(OPATH)/%.o: $(CPATH)/%.c
	@echo "$(NAME) : Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "$(NAME) : Creating objs directory"
	@$(MKDIR) $@

clean:
	@echo "$(NAME) : Deleting objs"
	@$(RM) -rf $(OPATH)

fclean: clean
	@echo "$(NAME) : Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\033[32mDone !\033[0m"

re: fclean all

test: all
	@gcc main.c -I./include -L. -lftprintf
	@./a.out
	@rm a.out

