# Target executable names
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

# Source files
CLIENT_SRC = ./mandatory/client.c ./mandatory/helper.c
SERVER_SRC = ./mandatory/server.c ./mandatory/helper.c

CLIENT_SRC_BONUS = ./bonus/client_bonus.c ./bonus/helper_bonus.c
SERVER_SRC_BONUS = ./bonus/server_bonus.c ./bonus/helper_bonus.c

# Object files
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)
SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)

# Default target
all: $(CLIENT) $(SERVER)

# Rule to build the client
$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build the server
$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Bonus targets
bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

# Rule to build the bonus client
$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to build the bonus server
$(SERVER_BONUS): $(SERVER_OBJ_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@ $(RM) $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_OBJ_BONUS) $(SERVER_OBJ_BONUS)

# Full clean rule (objects and executables)
fclean: clean
	@ $(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus