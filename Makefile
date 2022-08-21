CC = g++
CCFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU -lGLEW
all: 
	$(CC) main.cpp -o main $(CCFLAGS)

run:
	./main