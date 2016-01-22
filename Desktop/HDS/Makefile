CC = g++
LIBS = -lpthread
FLAGS = 
EXECS = rwlocks

all: $(EXECS)

rwlocks: test.cpp
	$(CC) $(FLAGS) -o $@ $? $(LIBS) 

clean:
	rm $(EXECS)
