CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
BONUS_NAME = pipex
SRC = mandatory/ft_split.c mandatory/ft_strdup.c mandatory/ft_strjoin.c mandatory/ft_strlcat.c mandatory/ft_strlcpy.c mandatory/ft_strlen.c mandatory/ft_strncmp.c mandatory/ft_strnstr.c mandatory/pipex.c \
	mandatory/utils.c mandatory/ft_split_utils.c mandatory/ft_putstr_fd.c
SRCB = bonus/ft_putstr_fd_bonus.c bonus/ft_split_utils_bonus.c bonus/ft_strjoin_bonus.c bonus/ft_strlcpy_bonus.c bonus/ft_strncmp_bonus.c bonus/utils_bonus_0.c bonus/utlis_bonus_2.c \
	bonus/ft_split_bonus.c bonus/ft_strdup_bonus.c bonus/ft_strlcat_bonus.c bonus/ft_strlen_bonus.c bonus/ft_strnstr_bonus.c bonus/utils_bonus_1.c bonus/pipex_bonus.c
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bonus:	.bonus

.bonus:	$(OBJB)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJB)
	touch .bonus

mandatory/%.o: mandatory/%.c mandatory/pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME) .bonus

re: fclean all