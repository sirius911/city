CC	= gcc    #Commande du compilateur
CFLAGS	= -O3 #Option d'optimisation du programme
LDFLAGS	= -lSDL 
NAME	= test-sdl  #Nom du programme à modifier

SRC = test-sdl2.c

all: $(NAME)

OBJ 	= $(SRC:.c=.o)

c.o:	$(CC) $(CFLAGS) -c $< -o ${<:c.=.o}
	@echo "compilation : "$< "\033[32mok\033[0m"

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:	
	rm -fr *.o

fclean: clean
	rm -fr ${NAME}

re:	fclean all

.PHONY: all clean fclean re
