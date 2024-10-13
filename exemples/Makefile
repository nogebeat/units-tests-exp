##
## EPITECH PROJECT, 2023
## make
## File description:
## make
##

CC = gcc

NAME = division_program

SRC = src/division.c \

MAIN = src/main.c

TEST_SRC = tests/test_division.c \

OBJS = $(SRC:.c=.o)

CFLAGS += -I./include/ -g -lgcov -lm

FTEST = -coverage -lcriterion

BIZ = *~ *.log a.out *.gcov *.gcda *.gcno

all: $(NAME)

$(NAME): 
	$(CC) -o $(NAME) $(SRC) $(MAIN) $(CFLAGS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) unit_tests $(BIZ)

re: fclean all

unit_tests: fclean $(NAME)
	$(CC) -o unit_tests $(SRC) $(TEST_SRC) $(FTEST)

tests_run: unit_tests
	./unit_tests
	gcovr
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches
