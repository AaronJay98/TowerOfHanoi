/*
 * Stack.h
 *
 *  Created on: Feb 25, 2019
 *      Author: kennethpadron
 */

#ifndef STACK_H_
#define STACK_H_
#include  <iostream>
using namespace std;

struct STACK_NODE
{
	int disk;
	STACK_NODE *next;
};

class Stack
{
public:
	Stack();
	virtual ~Stack();
	int pop();
	void push(int n);
	int peek() const;
	void init();
	bool IsEmpty();
	//bool operator!=(Stack);
	int numDisks;
	STACK_NODE *top;
	STACK_NODE *bottom;
	char name;
	void operator=(Stack*);
	bool operator==(Stack*);
};

#endif /* STACK_H_ */
