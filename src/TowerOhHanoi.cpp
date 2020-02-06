//============================================================================
// Name        : TowersOfHanoi.cpp
// Author      : Kenneth Padron
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "List.h"
using namespace std;

int main()
{
	Queue Positions;
	int userInput = 0;
	int i = 0;

	cout << "Enter number of disks:" << endl;
	cin >> userInput;

	Stack* A_Peg = new Stack();
	A_Peg->name = 'A';
	Stack* B_Peg = new Stack();
	B_Peg->name = 'B';
	Stack* C_Peg = new Stack();
	C_Peg->name = 'C';

	for(int i = 0; i < userInput; i++) {
		A_Peg->push(userInput - i);
	}

	Positions.enqueue(A_Peg, B_Peg, C_Peg);

	while(true) {
		i++;
		cout << i << endl;
		if(Positions.dequeue()) {
			break;
		}
	}



	return 0;
}
