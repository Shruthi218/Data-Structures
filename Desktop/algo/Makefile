all: insertionsort heapsort countingsort

insertionsort: insertionsort.cpp
	g++ -c insertionsort.cpp
	g++ -c heapsort.cpp
	g++ -c countingsort.cpp
	g++ -c -std=c++11 final.cpp
	g++ -o insertionsort insertionsort.o heapsort.o countingsort.o final.o


heapsort: heapsort.cpp
	g++ -c insertionsort.cpp
	g++ -c heapsort.cpp
	g++ -c countingsort.cpp
	g++ -c -std=c++11 final.cpp
	g++ -o heapsort insertionsort.o heapsort.o countingsort.o final.o


countingsort: countingsort.cpp
	g++ -c insertionsort.cpp
	g++ -c heapsort.cpp
	g++ -c countingsort.cpp
	g++ -c -std=c++11 final.cpp
	g++ -o countingsort insertionsort.o heapsort.o countingsort.o final.o

clean:
	rm -rf *.o insertionsort heapsort countingsort
