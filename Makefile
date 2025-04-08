C_NAME = client
S_NAME = server
CC = cc
FLAGS = -Wall -Werror -Wextra
SRC_S = server.c
OBJ_S = $(SRC_S:.c=.o)
SRC_c = client.c
OBJ_C = $(SRC_c:.c=.o)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

all: $(C_NAME) $(S_NAME)

$(C_NAME): $(OBJ_C)
	@$(CC) $(FLAGS) -o $(C_NAME) $(OBJ_C)

$(S_NAME): $(OBJ_S)
	@$(CC) $(FLAGS) -o $(S_NAME) $(OBJ_S)

clean:
	rm -rf $(OBJ_S) $(OBJ_C) $(C_NAME) $(S_NAME)

fclean: clean
	rm -rf $(OBJ_S) $(OBJ_C) $(C_NAME) $(S_NAME)

re: clean all

.PHONY: clean
