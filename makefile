NAME = fdf.a
SRCFILES = main.c
SRCDIR = src
OBJDIR = obj
SRCS = $(addprefix $(SRCDIR)/, $(SRCFILES))
OBJS = $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = -I inc

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C inc/libft
	$(MAKE) -C inc/minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) inc/libft/libft.a inc/minilibx-linux/libmlx_Linux.a -o $(NAME)

$(OBJS): $(SRCS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | obj
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

obj:
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(name)

debug:
	cc src/*.c -g -I inc inc/libft/libft.a -o debug

re: fclean all

PHONY: clean fclean re debug