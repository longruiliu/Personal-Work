CC = gcc
FLAGS = -g -std=c99
test:client server
client:source.o client.o
	$(CC) -o client source.o client.o $(FLAGS)
source.o:source.c
	$(CC) -c source.c $(FLAGS)
client.o:client.c
	$(CC) -c client.c $(FLAGS)
server:source.o server.o
	$(CC) -o server source.o server.o $(FLAGS)
server.o:server.c
	$(CC) -c server.c $(FLAGS)
clean:
	rm *.o
