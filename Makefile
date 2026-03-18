NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
INCLUDE = -I include

SRC_DIR = src/
BONUS_DIR = bonus/

SRC = \
$(SRC_DIR)push_swap.c \
$(SRC_DIR)sort.c \
$(SRC_DIR)push_three.c \
$(SRC_DIR)tiny_sort.c \
$(SRC_DIR)helpers.c \
$(SRC_DIR)helpers2.c \
$(SRC_DIR)operations.c \
$(SRC_DIR)operations2.c \
$(SRC_DIR)ft_split.c \
$(SRC_DIR)ft_substr.c

SRC_BONUS = \
$(BONUS_DIR)checker_bonus.c \
$(BONUS_DIR)sort_bonus.c \
$(BONUS_DIR)ft_split_bonus.c \
$(BONUS_DIR)get_next_line_bonus.c \
$(BONUS_DIR)helpers_bonus.c \
$(BONUS_DIR)helpers2_bonus.c \
$(BONUS_DIR)operations_bonus.c \
$(BONUS_DIR)operations2_bonus.c \
$(BONUS_DIR)operations3_bonus.c \
$(SRC_DIR)ft_substr.c

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

DEP = $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

all: ${NAME}

${NAME}: ${OBJ}
	$(CC) ${CFLAGS} $(INCLUDE) ${OBJ} -o ${NAME}

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJ_BONUS}
	$(CC) ${CFLAGS} $(INCLUDE) ${OBJ_BONUS} -o ${NAME_BONUS}

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f ${OBJ} ${OBJ_BONUS} ${DEP}

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}

re: fclean all

-include $(DEP)

.PHONY: all bonus clean fclean re