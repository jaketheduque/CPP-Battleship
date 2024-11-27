battleship: main.o DynamicArray.o BoardCoord.o Coord.o Board.o Ship.o Player.o AIPlayer.o UserPlayer.o
	g++ -g -o battleship main.o DynamicArray.o BoardCoord.o Coord.o Board.o Ship.o Player.o AIPlayer.o UserPlayer.o

main.o: main.cpp BoardCoord.h DynamicArray.cpp Coord.h Helper.h AIPlayer.h
	g++ -g -c main.cpp

UserPlayer.o: UserPlayer.h UserPlayer.cpp Player.h Coord.h
	g++ -g -c UserPlayer.cpp

AIPlayer.o: AIPlayer.h AIPlayer.cpp Player.h Coord.h
	g++ -g -c AIPlayer.cpp

Player.o: Player.h Player.cpp Board.h
	g++ -g -c Player.cpp

Board.o: Board.h Board.cpp
	g++ -g -c Board.cpp

Ship.o: Ship.h Ship.cpp BoardCoord.h DynamicArray.cpp Board.h Coord.h
	g++ -g -c Ship.cpp

BoardCoord.o: BoardCoord.h BoardCoord.cpp Coord.h
	g++ -g -c BoardCoord.cpp

Coord.o: Coord.h Coord.cpp
	g++ -g -c Coord.cpp

DynamicArray.o: DynamicArray.cpp
	g++ -g -c DynamicArray.cpp

clean:
	rm *.o battleship