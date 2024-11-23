# *********************************** NAME *********************************** #

NAME	= libftprintf.a

# ****************************** SHELL COMMAND ******************************* #

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm
FINDBYNAME	= find -name
PRINT		= echo
WAIT1		= sleep 1
WAIT0.3		= sleep 0.3
ERASE		= printf "\033[2K\r"

# ********************************** FILES *********************************** #

SRCS	= ft_printf.c ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

# ************************************ ALL *********************************** #

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

%.o:	%.c
		@$(CC) $(CFLAGS) -c $< -o $@

# ********************************** CLEAN *********************************** #

clean:
		@$(PRINT) -n "$(R)Cleaning objects files ";$(WAIT0.3)
		@$(PRINT) -n ".";$(WAIT0.3)
		@$(PRINT) -n ".";$(WAIT0.3)
		@$(PRINT) -n ".";$(WAIT1);$(ERASE)
		@$(RM) -f $(OBJS)
		@$(PRINT) "$(G)object files removed"

# ********************************** FCLEAN ********************************** #

fclean:	clean
		@$(PRINT) -n "$(R)Cleaning library ";$(WAIT0.3)
		@$(PRINT) -n ".";$(WAIT0.3)
		@$(PRINT) -n ".";$(WAIT0.3)
		@$(PRINT) -n ".";$(WAIT1);$(ERASE)
		@$(RM) -f $(NAME)
		@$(PRINT) "$(G)Library removed"

# ************************************ RE ************************************ #

re:	fclean all

# ********************************** PHONY *********************************** #

.PHONY:	all clean fclean re

# *********************************** COLOR ********************************** #

# BLACK
O	= \033[0m

#RED
R	= \033[0;31m
#GREEN
G	= \033[0;32m
#YELLOW
Y	= \033[0;33m
#VIOLET
V	= \033[0;34m