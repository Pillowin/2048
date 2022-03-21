S			:=	src/
I			:=	header/
O			:=	obj/

NAME		:=	2048
SRC			:=	$(wildcard $S*.c $S*/*.c)
OBJ			:=	$(SRC:$S%.c=$O%.o)

CC			:=	cc

CFLAGS		+=	-I$I
CFLAGS		+=	-Wall -Wextra -Werror -MMD

LDFLAGS		+=	-I$I

MAKEFLAGS	+= --no-print-directory

RM			:=	/bin/rm -f
RMDIR		:=	/bin/rm -Rf

$O%.o: $S%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@ -lncurses

clean:
	$(RMDIR) $(wildcard $(NAME).dSYM)
	$(RMDIR) $O

fclean: clean
	$(RM) $(NAME)

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re

-include $(OBJ:.o=.d)
