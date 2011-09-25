FLAGS = $(CFLAGS)
CC = gcc $(FLAGS)
HEADS = porrinha.h

porrinha:     main.o jogo.o num_jogadores.o palitos.o extras.o telas.o palpites.o
	$(CC) main.o jogo.o num_jogadores.o palitos.o extras.o telas.o palpites.o \
	-o porrinha   

main.o: $(HEADS)
	$(CC) -c main.c

jogo.o: $(HEADS) boleanos.h
	$(CC) -c jogo.c

num_jogadores.o: $(HEADS)
	$(CC) -c num_jogadores.c

palitos.o: $(HEADS)
	$(CC) -c palitos.c

extras.o: $(HEADS)
	$(CC) -c extras.c

telas.o: $(HEADS)
	$(CC) -c telas.c

palpites.o: $(HEADS) boleanos.h
	$(CC) -c palpites.c

clean: $(HEADS)
	rm -f *.o porrinha 

debug: $(HEADS)
	$(CC) -c jogo.c -D__DEBUG__
