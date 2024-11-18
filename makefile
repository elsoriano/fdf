NAME = fdf.a
SRCFILES = main.c \
			parse_map.c \
			draw.c
SRCDIR = src
OBJDIR = obj
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS = $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = inc

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C inc/libft
	$(MAKE) -C inc/minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) inc/libft/libft.a inc/minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -o $(NAME)

$(OBJS): $(SRCS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@

obj:
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(name)

debug:
	rm -rf debug.a
	gcc src/*.c -g -fsanitize=address -I inc inc/libft/libft.a inc/minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -o debug.a

re: fclean all

PHONY: clean fclean re debug