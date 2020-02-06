/*
 * Queue.h
 *
 *  Created on: Feb 25, 2019
 *      Author: kennethpadron
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include  <iostream>
#include "Stack.h"
#include "List.h"
using namespace std;

class Queue
{
private:
	struct QUEUE_NODE
	 {
		QUEUE_NODE *next;
		Stack* A, *B, *C;
		List* Moves;
	 };

	QUEUE_NODE *rear;
	QUEUE_NODE *Existed;

public:
	Queue();
	virtual ~Queue();
	bool dequeue();
	void enqueue(Stack*, Stack*, Stack*);
	void enqueue(Stack*, Stack*, Stack*, List*);
	Stack* peek() const;
	void init();
	bool IsEmpty();
	bool checkLegalMoves(QUEUE_NODE*);
	bool isFound(Stack*, Stack*);
	QUEUE_NODE *front;
	bool checkExists(Stack*, Stack*, Stack*);
	void deleteExisted(void);
	int numExisted;

};

#endif /* QUEUE_H_ */
