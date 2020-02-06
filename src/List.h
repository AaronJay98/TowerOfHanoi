/*
 * List.h
 *
 *  Created on: Feb 25, 2019
 *      Author: kennethpadron
 */

#ifndef LIST_H_
#define LIST_H_
#include "Stack.h"
#include <iomanip>

struct Move
{
	int disk;
	Move* next;
	Stack *to, *from;
};

class List
{
public:
	List();
	virtual ~List();

	Move* head;
	int numMoves;
	void Print(void);
	void init(void);
	void operator=(List*);
	void push(int, Stack*, Stack*);
};

#endif /* LIST_H_ */
