NAME = so_long
LIBMLX = ./MLX42
CC = cc
CFLAGS = -Wextra -Wall -Werror -g
HEADERS	= -I ./include -I $(LIBMLX)/include
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
LIBS = $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS = $(shell find ./src -iname "*.c") so_long.c
OBJS = ${SRCS:.c=.o}

all: $(LIBMLX) $(NAME)

$(LIBMLX):
	if [ ! -d "$(LIBMLX)" ]; then \
	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX); \
	cmake -S $(LIBMLX) -B $(LIBMLX)/build -DDEBUG=1 && make -C $(LIBMLX)/build -j4; \
	fi

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(LIBFT) $(OBJS) $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -L$(LIBFTDIR) -lft $(HEADERS) -o $(NAME)

$(LIBFT):
	@make -C ./libft

clean:
	@make clean -C $(LIBFTDIR)
	@rm -rf $(OBJS) $(LIBMLX)/build

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -fr $(LIBMLX)
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
