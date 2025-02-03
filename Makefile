CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
BONUS_NAME = pipex
SRC = mandatory/ft_split.c mandatory/ft_strdup.c mandatory/ft_strjoin.c mandatory/ft_strlcat.c mandatory/ft_strlcpy.c mandatory/ft_strlen.c mandatory/ft_strncmp.c mandatory/ft_strnstr.c mandatory/pipex.c mandatory/utils.c mandatory/ft_split_utils.c
SRCB = bonus/ft_split.c bonus/ft_strdup.c bonus/ft_strjoin.c bonus/ft_strlcat.c bonus/ft_strlcpy.c bonus/ft_strlen.c bonus/ft_strncmp.c bonus/ft_strnstr.c bonus/pipex_bonus.c bonus/utils_bonus.c bonus/utils.c bonus/ft_split_utils.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) mandatory/pipex.h
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(OBJB) bonus/pipex.h
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJB)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all