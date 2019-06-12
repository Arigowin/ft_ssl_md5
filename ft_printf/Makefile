CC =		/usr/bin/clang
RM =		/bin/rm
MAKE =		/usr/bin/make
MKDIR =		/bin/mkdir
AR =		/usr/bin/ar
RANLIB =	/usr/bin/ranlib

NAME = libftprintf.a

ROOT =		$(shell /bin/pwd)
OPATH =		$(ROOT)/obj
CPATH =		$(ROOT)/src
HPATH =		$(ROOT)/include
LIBPATH =	$(ROOT)/libft
LIBOPATH =	$(LIBPATH)/obj
LIBCPATH =	$(LIBPATH)/srcs
LIBHPATH =	$(LIBPATH)/includes

CFLAGS = -Wall -Werror -Wextra -I $(HPATH) -I $(LIBHPATH) -fPIC

SRC =	chaining_list.c \
		conv_c.c \
		conv_d.c \
		conv_f.c \
		conv_f2.c \
		conv_o.c \
		conv_o2.c \
		conv_p.c \
		conv_pct.c \
		conv_s.c \
		conv_u.c \
		conv_x.c \
		conversion_manager.c \
		ft_add_char.c \
		ft_add_char_back.c \
		ft_add_char_front.c \
		ft_add_n_char.c \
		ft_add_symbole.c \
		ft_nbrlen.c \
		ft_print_n_char.c \
		ft_printf.c \
		ft_prntnum.c \
		ft_lltoa.c \
		ft_ptr_to_hex.c \
		ft_putupper.c \
		ft_remove_char.c \
		ft_strncount.c \
		no_conv.c \
		other_conv.c \
		parsing.c \
		parsing2.c \
		print_all.c

LIB_SRC =	ft_atoh.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_copyt2d.c \
			ft_free_tbl_s.c \
			ft_get_index.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lstadd.c \
			ft_lstcount.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstpushback.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_color.c \
			ft_putchar_color_fd.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_color.c \
			ft_putnbr_fd.c \
			ft_putnbrendl.c \
			ft_putstr.c \
			ft_putstr_color.c \
			ft_putstr_color_fd.c \
			ft_putstr_fd.c \
			ft_splittolst.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncount.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strproperjoin.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c \
			str_toupper.c

OBJ = $(patsubst %.c, $(OPATH)/%.o, $(SRC))
LIB_OBJ = $(patsubst %.c, $(LIBOPATH)/%.o, $(LIB_SRC))

.PHONY: all clean fclean re

all: $(OPATH) $(LIBOPATH) $(NAME)

$(NAME): $(OPATH) $(LIBOPATH) $(OBJ) $(LIB_OBJ)
	@echo "$(NAME) : Building $@"
	@$(AR) rc $@ $(OBJ) $(LIB_OBJ)
	@$(RANLIB) $@
	@echo "\033[32mDone !\033[0m"

$(OPATH)/%.o: $(CPATH)/%.c
	@echo "$(NAME) : Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBOPATH)/%.o: $(LIBCPATH)/%.c
	@echo "$(NAME) : Creating file $@"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OPATH):
	@echo "$(NAME) : Creating objs directory"
	@$(MKDIR) $@

$(LIBOPATH):
	@echo "$(NAME) : Creating lib objs directory"
	@$(MKDIR) $@

clean:
	@echo "$(NAME) : Deleting objs"
	@$(RM) -Rf $(OPATH)
	@$(RM) -Rf $(LIBOPATH)

fclean: clean
	@make fclean -C $(LIBPATH)
	@echo "$(NAME) : Deleting $(NAME)"
	@$(RM) -f $(NAME)
	@echo "\033[32mDone !\033[0m"

re: fclean all
