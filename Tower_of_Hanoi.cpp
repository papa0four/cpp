//Tower of Hanoi using Stacks!
#include <iostream>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <chrono>
#include <stdlib.h>
#include <conio.h>

int Setup(std::stack<int>& tower, int n);
void MoveStackOfNSize(std::stack<int>& source, std::stack<int>& dest, std::stack<int>&, int n);
void display();
void move(std::stack<int>& source, std::stack<int>& dest);
static int numMoves = 0;
clock_t begin, end;
double time_spent;

std::stack<int> TowerA;
std::stack<int> TowerB;
std::stack<int> TowerC;

int main()
{

	int n;

	// prompt player to enter desired number of discs to play
	std::cout << "Please enter number of discs you like to play: " << std::endl;
	// accepts users input
	std::cin >> n;
	// output for better readability
	std::cout << "=============================" << std::endl;
	// start game timer
	begin = clock();	n = Setup(TowerA, n);
	// call recursive move stack function....
	//... Tower A = source tower, Tower C = destination tower & Tower B = auxillary or temporary disc storage tower
	MoveStackOfNSize(TowerA, TowerC, TowerB, n);
	
	getchar(); getchar();
	return 0;

}

//Arguments: std::stack<int>& towerA - a stack container that will be setup with a number of discs 

//           int n - a number that represents the number of discs to load on to the tower stack

//Return     the number of discs that were loaded on to the tower 

//Functionality: Load a number of discs in ascending order on to the stack 

int Setup(std::stack<int>& tower, int n)

{
	// for loop to iterate through the number of discs and subtract 1 disc for each iteration of the loop
	for (int i = n; i > 0; i--)
	{
		// push the n number of the discs to the tower stack
		tower.push(i);
	}
	// return the number
	return n;
}

void move(std::stack<int> &source, std::stack<int> &dest)
{
	
	// create a temporary value to hold discs during move process
	int tempValue = 0;
	// if the source tower has no discs....
	if (source.empty())
	{
		// ... return nothing (i.e. break the program)
		return;
	}
	// if there are discs within the destination tower...
	else if (!dest.empty())
	{
		// ... and if the first disc of the cource tower is greater than the first disc of the destination tower
		if (source.top() > dest.top())
		{
			// throw an error stating that this is an invalid move
			throw std::invalid_argument("Destination disc is smaller than current disc");
		}
	}
	// set the temporary value to the top disc value of the source tower
	tempValue = source.top();
	// remove the top disc from the source tower
	source.pop();
	// put the top most disc of the source tower into the destination tower
	dest.push(tempValue);
	// increment the number of moves counter for every disc move made
	numMoves++;

	display();
	
}


//Arguments: std::stack<int>& source - the tower that discs will be moved from

//           std::stack<int>& dest - the tower that discs will be moved to 

//           std::stack<int>& temp - a tower that can hold discs 

//           int n - the number of discs on the source tower

//Return     none

//Functionality: Move a tower from source to another tower. 

void MoveStackOfNSize(std::stack<int>& source, std::stack<int>& dest, std::stack<int>& temp, int n)

{
	
	// if there are no discs at all...
	if (n == 0)
	{
		// ... return nothing (i.e. break the program)
		return;
	}
	// if there is only one disc...
	else if (n == 1)
	{
		// ...move the only disc to the destination tower by calling the move function above
		move(source, dest);
	}
	// if there are more than 1 disc...
	else
	{
		// recursive function to move all but bottom disc to temp tower
		MoveStackOfNSize(source, temp, dest, n - 1);
		// pushing top disc of source tower to destination tower
		move(source, dest);
		// recursive function to move discs from temp tower to destination tower
		MoveStackOfNSize(temp, dest, source, n - 1);

	}	
}

//Arguments: std::stack<int>& tower - a tower that has discs to dispay

//Return     none

//Functionality: Display the contents of a tower

void display()

{
	// display the number of moves
	std::cout << "Move: " << numMoves << std::endl;
	// create a temp storage of Tower A
	std::stack<int>TowerACopy = TowerA;
	// create a temp storage of Tower B
	std::stack<int>TowerBCopy = TowerB;
	// create a temp storage of Tower C
	std::stack<int>TowerCCopy = TowerC;

	std::cout << std::endl;

	// create a standard string output variable that clears each Tower after printing
	std::string output = "";

	// while temporary Tower A is not empty...
	while (!TowerACopy.empty())
	{
		// ... output the contents of Tower A in descending order...
		output = std::to_string(TowerACopy.top()) + output;
		// ... and destroy contents of temporary Tower A
		TowerACopy.pop();
	}
	// create actual display of each printed version of Tower A as it runs through the program
	std::cout << "Tower A: -- " << output << std::endl;
	// set output variable back to empty string
	output = "";
	// while Temporary Tower B is not empty...
	while (!TowerBCopy.empty())
	{
		// ... output the contents of Tower B in descending order...
		output = std::to_string(TowerBCopy.top()) + output;
		//... and destroy contents of temporary Tower B
		TowerBCopy.pop();
	}
	// create actual display of each printed version of Tower B as it runs through the program
	std::cout << "Tower B: -- " << output << std::endl;
	// set output variable back to empty string
	output = "";
	// while Temporary Tower C is not empty...
	while (!TowerCCopy.empty())
	{
		// ... output the contents of Tower C in descending order...
		output = std::to_string(TowerCCopy.top()) + output;
		//... and destroy contents of temporary Tower C
		TowerCCopy.pop();
	}
	// create actual display of each printed version of Tower C as it runs through the program
	std::cout << "Tower C: -- " << output << std::endl;
	// set output variable back to empty string
	output = "";
	// create new line for readability within output
	std::cout << std::endl;
	std::cout << "time to run: " << time_spent << " (sec)" << std::endl;
	// creates a line of '+' characters to separate each move within the game
	std::cout << "+++++++++++++++++++++++++++++" << std::endl;
	// create new line for readability within output
	std::cout << output << std::endl;

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

}