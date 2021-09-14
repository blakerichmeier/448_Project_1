battleship: main.o Executive.o gameBoard.o test_input.o player.o user_input.o ship.o
	g++ -g -std=c++11 -Wall main.o Executive.o gameBoard.o test_input.o player.o user_input.o ship.o -o battleship

main.o: main.cpp Executive.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.cpp Executive.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c Executive.cpp

gameBoard.o: gameBoard.cpp gameBoard.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c gameBoard.cpp

test_input.o: test_input.cpp test_input.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c test_input.cpp

player.o: Player.cpp Player.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c Player.cpp

user_input.o: user_input.cpp user_input.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c user_input.cpp
	
ship.o: ship.cpp ship.hpp myDefines.h
	g++ -g -std=c++11 -Wall -c ship.cpp

clean:
	rm *.o battleship

run:
	./battleship
