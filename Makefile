
battleship: main.o Executive.o gameBoard.o user_input.o ship.o ai.o
	g++ -g -std=c++11 -Wall main.o Executive.o gameBoard.o user_input.o ship.o ai.o -o battleship

main.o: main.cpp Executive.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.cpp Executive.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

gameBoard.o: gameBoard.cpp gameBoard.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c gameBoard.cpp

user_input.o: user_input.cpp user_input.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c user_input.cpp
	
ship.o: ship.cpp ship.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c ship.cpp

ai.o: ai.cpp ai.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c ai.cpp

clean:
	rm *.o battleship

run:
	./battleship
