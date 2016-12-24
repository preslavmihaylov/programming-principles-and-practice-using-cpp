#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <cassert>
#include <vector>
#include <sstream>

using namespace std;

#define ROOMS_CNT (25)
#define ADJ_ROOMS_CNT (3)
#define PITS_CNT (3)
#define BATS_CNT (3)
#define NO_ROOM (-1)
#define ROOM_CONNECTIONS (ROOMS_CNT * ADJ_ROOMS_CNT)

bool gameOver = false;

struct Room
{
	bool isBatPresent = false;
	bool isPitPresent = false;
	int adjacentRooms[ADJ_ROOMS_CNT] = { NO_ROOM };
	
	bool hasUninitializedRooms() 
	{ 
		for (int i = 0; i < ADJ_ROOMS_CNT; ++i) 
			if (this->adjacentRooms[i] == NO_ROOM) return true;
		return false;
	}
	
	bool containsConnection(int con)
	{
		for (int i = 0; i < ADJ_ROOMS_CNT; ++i)
			if (this->adjacentRooms[i] == con) return true;
		return false;
	}

	bool isRoomClear()
	{
		return (this->isBatPresent == false) &&
		       (this->isPitPresent == false);
	}

	bool containsRoom(int room)
	{
		for (int i = 0; i < ADJ_ROOMS_CNT; ++i)
			if (this->adjacentRooms[i] == room) return true;
		return false;
	}
};

Room maze[ROOMS_CNT];
bool isWumpAwaken = false;
int wumpLocation = NO_ROOM;
int humanLocation = NO_ROOM;
int arrowsCnt = 5;

void outputDebugInfo()
{
	for (int i = 0; i < ROOMS_CNT; ++i)
	{
		cout << "Room " << i << ": ";
		if (maze[i].isBatPresent) cout << "BAT ";
		if (maze[i].isPitPresent) cout << "PIT ";
		for (int j = 0; j < ADJ_ROOMS_CNT; ++j)	
			cout << maze[i].adjacentRooms[j] << " ";
		cout << endl;
	}

	cout << "HUMAN LOC: " << humanLocation << endl;
	cout << "ARROWS CNT: " << arrowsCnt << endl;
	cout << "WUMP LOC: " << wumpLocation << endl;
	cout << "Is Wump awake? " << isWumpAwaken << endl;
}

void randomizeArray(int * arr, int size)
{
	int temp;
	int genPos;
	for (int i = 0; i < size; ++i)
	{
		genPos = rand() % size;
		
		temp = arr[i];
		arr[i] = arr[genPos];
		arr[genPos] = temp;
	}
}

bool isNumber(const string& str)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (!isdigit(str[i])) return false;
	}

	return true;
}

void connectRooms(int first, int second)
{
	int fIndex = 0;
	int sIndex = 0;
	while (maze[first].adjacentRooms[fIndex] != NO_ROOM) ++fIndex;
	while (maze[second].adjacentRooms[sIndex] != NO_ROOM) ++sIndex;

	// assert that rooms are still available
	if (fIndex >= ADJ_ROOMS_CNT || sIndex >= ADJ_ROOMS_CNT) 
	{
		assert(false);
	}

	maze[first].adjacentRooms[fIndex] = second;
	maze[second].adjacentRooms[sIndex] = first;
}

void generateConnections()
{
	// every room has ADJ_ROOMS_CNT connections
	int roomConnectionsQueue[ROOM_CONNECTIONS];
	int i;
	int j;
	int currentRoomIndex;

	// generate initial list of room connections
	for (i = 0; i < ROOM_CONNECTIONS; i += ADJ_ROOMS_CNT)
	{
		currentRoomIndex = i / ADJ_ROOMS_CNT;
		
		// set the current room index ADJ_ROOMS_CNT times in the array 
		// as it will be connected ADJ_ROOMS_CNT times
		for (j = 0; j < ADJ_ROOMS_CNT; ++j)
		{
			roomConnectionsQueue[i + j] = currentRoomIndex;
		}
	}
	
	randomizeArray(roomConnectionsQueue, ROOM_CONNECTIONS);
	
	int roomConnectionIndex = 0;
	for (i = 0; i < ROOMS_CNT; ++i)
	{
		for (j = 0; j < ADJ_ROOMS_CNT; ++j)
		{
			if (maze[i].adjacentRooms[j] != NO_ROOM)
			{
				continue;
			}

			int currentRoom = roomConnectionsQueue[roomConnectionIndex];
			while (!maze[currentRoom].hasUninitializedRooms()) 
			{
				++roomConnectionIndex;
				currentRoom = roomConnectionsQueue[roomConnectionIndex];
			}
			
			connectRooms(i, currentRoom);
			++roomConnectionIndex;
		}
	}
}

void constructMaze()
{
	int i;
	int generated;
	srand(time(NULL));
	// initially, wump is not awake
	isWumpAwaken = false;

	for (i = 0; i < ROOMS_CNT; ++i)
	{
		maze[i].isBatPresent = false;
		maze[i].isPitPresent = false;
		for (int j = 0; j < ADJ_ROOMS_CNT; ++j)
		{
			maze[i].adjacentRooms[j] = NO_ROOM;
		}
	}

	// generate pits
	for (i = 0; i < PITS_CNT; ++i)
	{
		do
		{
			generated = rand() % ROOMS_CNT;
		} while (maze[generated].isBatPresent || 
			     maze[generated].isPitPresent);

		maze[generated].isPitPresent = true;
	}
	
	// generate bats
	for (i = 0; i < BATS_CNT; ++i)
	{
		do
		{
			generated = rand() % ROOMS_CNT;
		} while (maze[generated].isBatPresent || 
			     maze[generated].isPitPresent);
		
		maze[generated].isBatPresent = true;
	}

	generateConnections();

	// generate human starting location
	do
	{
		generated = rand() % ROOMS_CNT;
	// do not spawn human on a pit or a bat
	} while (maze[generated].isRoomClear() == false);
	humanLocation = generated;

	// generate wump starting location
	do
	{
		generated = rand() % ROOMS_CNT;
	// do not spawn wump on a pit or a bat
	// do not spawn wump on the location of the human
	} while (maze[generated].isRoomClear() == false ||
			 humanLocation == generated);
	wumpLocation = generated;
}

void printLocationInfo()
{
	cout << "You are currently in room " << humanLocation << ". ";
	cout << "You have " << arrowsCnt << " arrows left. ";
	cout << "Adjacent rooms are ";

	bool isBatNearby = false;
	bool isWumpNearby = false;
	bool isPitNearby = false;
	for (int i = 0; i < ADJ_ROOMS_CNT; ++i)
	{
		int adjacentRoom = maze[humanLocation].adjacentRooms[i];
		
		if (maze[adjacentRoom].isBatPresent) isBatNearby = true;
		if (maze[adjacentRoom].isPitPresent) isPitNearby = true;
		if (wumpLocation == adjacentRoom) isWumpNearby = true;

		cout << adjacentRoom;
		if (i != ADJ_ROOMS_CNT - 1) 
		{
			cout << ", ";
		}
		else 
		{
			cout << ". ";
		}
	}
	cout << '\n';

	if (isBatNearby) cout << "I hear a bat.\n";
	if (isPitNearby) cout << "I feel a breeze.\n";
	if (isWumpNearby) cout << "I smell the wumpus.\n";
}

void moveWumpus()
{
	if (isWumpAwaken)
	{
		int destAdjRoomIndex = rand() % ADJ_ROOMS_CNT;
		wumpLocation = maze[wumpLocation].adjacentRooms[destAdjRoomIndex];
	}
}

void shootArrow(int destRoom)
{
	--arrowsCnt;
	if (wumpLocation == destRoom)
	{
		gameOver = true;
		throw runtime_error("You have killed the wumpus! Congratulations");
	}
	else if (arrowsCnt <= 0)
	{
		gameOver = true;
		throw runtime_error(
			"You have run out of arrows. "
			"Now you can just wait for the wumpush to eat you! Game over");
	}
	else
	{
		isWumpAwaken = true;
		throw runtime_error("Drats! You have missed");
	}
}

void moveHuman(int destRoom)
{
	humanLocation = destRoom;

	// process dangers
	if (humanLocation == wumpLocation)
	{
		gameOver = true;
		throw runtime_error("You have been eaten by the wump");
	}
	if (maze[humanLocation].isPitPresent)
	{
		gameOver = true;
		throw runtime_error("You have fallen into a pit. Game over");
	}
	else if (maze[humanLocation].isBatPresent)
	{
		destRoom = rand() % ROOMS_CNT;
		cout << "You have encountered a bat. "
			 << "It has transported you to room "
			 << destRoom << '\n';
		moveHuman(destRoom);
	}
}

void processCommand(const string& command, const vector<string>& args)
{
	if (command == "move")
	{
		if (args.size() != 1) 
		{
			throw runtime_error("Invalid number of command arguments invoked");
		}
		
		if (!isNumber(args[0])) throw runtime_error("Invalid argument " + args[0]);
		
		int destRoom = stoi(args[0]);
		
		if (maze[humanLocation].containsRoom(destRoom))
		{
			moveHuman(destRoom);
		}
		else
		{
			throw runtime_error("cannot reach destination room");
		}
	}
	else if (command == "shoot")
	{
		if (args.size() != 1) 
		{
			throw runtime_error("Invalid number of command arguments invoked");
		}
		
		if (!isNumber(args[0])) throw runtime_error("Invalid argument " + args[0]);
		if (arrowsCnt <= 0) throw runtime_error("Out of arrows!");

		int destRoom = stoi(args[0]);
		
		if (maze[humanLocation].containsRoom(destRoom))
		{
			shootArrow(destRoom);
		}
		else
		{
			throw runtime_error("destination room is out of range");
		}
	}
	else
	{
		throw runtime_error("Unknown command " + command);
	}
}

void readCommand()
{
	string input;
	string command;
	string arg;
	vector<string> args;

	constructMaze();

	while (!gameOver)
	{
		//outputDebugInfo();
		printLocationInfo();

		cout << "> ";
		getline(cin, input);
		istringstream iss(input);
		iss >> command;
		args.clear();

		while (iss >> arg)
		{
			args.push_back(arg);
		}
		
		try
		{
			processCommand(command, args);
			moveWumpus();
		}
		catch (const runtime_error& e)
		{
			cout << e.what() << endl;
		}
	}
}

int main()
{
	readCommand();
	return 0;
}
