#Program name
NAME	= philo

# Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall

# Includes
INC			=	-I ./includes/\

# Sources
SRC_PATH	=	src/
SRC			=	philo.c \
				init.c \
				utils.c \
				utils2.c \
				routine.c

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@echo "Compiling philo..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC)
	@echo "Philo ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "Removing philo..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean