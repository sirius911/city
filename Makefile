CC	= clang    #Commande du compilateur
CFLAGS	= -Wall -Werror -Wextra 
LDFLAGS	= -lSDL 
NAME	= city  #Nom du programme à modifier

SRC = srcs/test-sdl2.c srcs/out.c srcs/city_tools.c srcs/python.c

all: $(NAME)

OBJ 	= $(SRC:.c=.o)

c.o:	@$(CC) $(CFLAGS) -c $< -o ${<:c.=.o}
	@echo "compilation : "$< "\033[32mok\033[0m"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:	
	rm -fr srcs/*.o

fclean: clean
	rm -fr ${NAME}

re:	fclean all

test:	
	./$(NAME)
.PHONY: all clean fclean re
