/*
 * Queue.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: kennethpadron
 */

#include "Queue.h"

Queue::Queue()
{
	// TODO Auto-generated constructor stub
	cout << "Creating Queue" << endl;
	front = nullptr;
	rear = nullptr;
	Existed = nullptr;
	numExisted = 0;
}

Queue::~Queue()
{
	// TODO Auto-generated destructor stub
	cout << "Destroying Queue" << endl;
	deleteExisted();
	init();
}

void Queue::enqueue(Stack* A, Stack* B, Stack* C)
{
    QUEUE_NODE *e = new QUEUE_NODE;
    e->A = A;
    e->B = B;
    e->C = C;
    e->Moves = new List();

    e->next = nullptr;
    if(front == nullptr) {
    	front = e;
    	rear = e;
    }
    else {
    	QUEUE_NODE *iterate = front;
    	while(iterate != rear) {
    		iterate = iterate->next;
    	}
    	rear->next = e;
    	rear = e;
    }
}

void Queue::enqueue(Stack* A, Stack* B, Stack* C, List* Moves)
{
	if(!checkExists(A, B, C)) {
		QUEUE_NODE *e = new QUEUE_NODE;
		e->A = A;
		e->B = B;
		e->C = C;
		e->Moves = Moves;
		e->next = nullptr;
		if(front == nullptr) {
			front = e;
			rear = e;
		}
		else if(front->next == nullptr) {
			front->next = e;
			rear = e;
		}
		else {
			QUEUE_NODE *iterate = front;
			while(iterate != rear) {
				iterate = iterate->next;
			}
			iterate->next = e;
			rear = e;
		}
	}
}

// return a pointer to the top element without removing it
Stack* Queue::peek() const
{
    if( !front )
    {
        cout << "Fatal peek() error - stack is empty" << endl;
        exit( -2 );
    }
    return front->B;
}

// remove and return the top element if there
bool Queue::dequeue()
{
    QUEUE_NODE *p = front;
    QUEUE_NODE *existIterator = Existed;
    //int n;
    if( front == nullptr )
    {
        cout << "Fatal error -- pop from empty stack!" << endl;
        exit( -1 );
    }
    if( front != nullptr ) // Why?
    {
    	if(checkLegalMoves(front)) {
		    delete p->A;
			delete p->B;
			delete p->C;
			delete p->Moves;
			delete p;
    		return true;
    	}
        front = front->next;
    }
    //n = p->key;
    if(existIterator == nullptr) {
    	existIterator = new QUEUE_NODE;
    	existIterator->A = new Stack();
    	existIterator->B = new Stack();
    	existIterator->C = new Stack();
    	existIterator->A->operator =(p->A);
    	existIterator->B->operator =(p->B);
    	existIterator->C->operator =(p->C);
    	existIterator->Moves = nullptr;
    	existIterator->next = nullptr;
    	Existed = existIterator;
    	numExisted++;
    }
    else {
    	while(existIterator->next != nullptr) {
    		existIterator = existIterator->next;
    	}
    	existIterator->next = new QUEUE_NODE;
    	existIterator = existIterator->next;
    	existIterator->A = new Stack();
    	existIterator->B = new Stack();
    	existIterator->C = new Stack();
		existIterator->A->operator =(p->A);
		existIterator->B->operator =(p->B);
		existIterator->C->operator =(p->C);
		existIterator->Moves = nullptr;
		existIterator->next = nullptr;
		numExisted++;
    }
    delete p->A;
    delete p->B;
    delete p->C;
    delete p->Moves;

    delete p;

    return false;
}

// clean out stack, returning all memory to system heap
void Queue::init()
{
    QUEUE_NODE *p = front;
    while(p)
    {
        p = p->next;
        delete front;
        front = p;
    }
    return;
}

// returns true if stack is empty, else false
bool Queue::IsEmpty()
{
    return front == nullptr;
}

bool Queue::checkLegalMoves(QUEUE_NODE* thePosition) {
	QUEUE_NODE copyPosition;
	if(thePosition->A->top != nullptr) {
		if(thePosition->B->top == nullptr || thePosition->A->top->disk < thePosition->B->top->disk) {
			copyPosition.A = new Stack();
			copyPosition.B = new Stack();
			copyPosition.C = new Stack();
			copyPosition.Moves = new List();
			copyPosition.A->operator =(thePosition->A);
			copyPosition.B->operator =(thePosition->B);
			copyPosition.C->operator =(thePosition->C);
			if(thePosition->Moves->head != nullptr) {
				copyPosition.Moves->operator =(thePosition->Moves);
			}
			copyPosition.B->push(copyPosition.A->pop());
			copyPosition.Moves->push(copyPosition.B->top->disk, copyPosition.A, copyPosition.B);
			if(isFound(copyPosition.A, copyPosition.C)) {
				copyPosition.Moves->Print();
				return true;
			}
			else {
				this->enqueue(copyPosition.A, copyPosition.B, copyPosition.C, copyPosition.Moves);
			}
		}
		if(thePosition->C->top == nullptr || thePosition->A->top->disk < thePosition->C->top->disk) {
			copyPosition.A = new Stack();
			copyPosition.B = new Stack();
			copyPosition.C = new Stack();
			copyPosition.Moves = new List();
			copyPosition.A->operator =(thePosition->A);
			copyPosition.B->operator =(thePosition->B);
			copyPosition.C->operator =(thePosition->C);
			if(thePosition->Moves->head != nullptr) {
				copyPosition.Moves->operator =(thePosition->Moves);
			}
			copyPosition.C->push(copyPosition.A->pop());
			copyPosition.Moves->push(copyPosition.C->top->disk, copyPosition.A, copyPosition.C);
			if(isFound(copyPosition.A, copyPosition.C)) {
				copyPosition.Moves->Print();
				return true;
			}
			else {
				this->enqueue(copyPosition.A, copyPosition.B, copyPosition.C, copyPosition.Moves);
			}
		}
	}
	if(thePosition->B->top != nullptr) {
		if(thePosition->A->top == nullptr || thePosition->B->top->disk < thePosition->A->top->disk) {
			copyPosition.A = new Stack();
			copyPosition.B = new Stack();
			copyPosition.C = new Stack();
			copyPosition.Moves = new List();
			copyPosition.A->operator =(thePosition->A);
			copyPosition.B->operator =(thePosition->B);
			copyPosition.C->operator =(thePosition->C);
			if(thePosition->Moves->head != nullptr) {
				copyPosition.Moves->operator =(thePosition->Moves);
			}
			copyPosition.A->push(copyPosition.B->pop());
			copyPosition.Moves->push(copyPosition.A->top->disk, copyPosition.B, copyPosition.A);
			if(isFound(copyPosition.A, copyPosition.C)) {
				copyPosition.Moves->Print();
				return true;
			}
			else {
				this->enqueue(copyPosition.A, copyPosition.B, copyPosition.C, copyPosition.Moves);
			}
		}
		if(thePosition->C->top == nullptr || thePosition->B->top->disk < thePosition->C->top->disk) {
			copyPosition.A = new Stack();
			copyPosition.B = new Stack();
			copyPosition.C = new Stack();
			copyPosition.Moves = new List();
			copyPosition.A->operator =(thePosition->A);
			copyPosition.B->operator =(thePosition->B);
			copyPosition.C->operator =(thePosition->C);
			if(thePosition->Moves->head != nullptr) {
				copyPosition.Moves->operator =(thePosition->Moves);
			}
			copyPosition.C->push(copyPosition.B->pop());
			copyPosition.Moves->push(copyPosition.C->top->disk, copyPosition.B, copyPosition.C);
			if(isFound(copyPosition.A, copyPosition.C)) {
				copyPosition.Moves->Print();
				return true;
			}
			else {
				this->enqueue(copyPosition.A, copyPosition.B, copyPosition.C, copyPosition.Moves);
			}
		}
	}
	if(thePosition->C->top != nullptr) {
		if(thePosition->A->top == nullptr || thePosition->C->top->disk < thePosition->A->top->disk) {
			copyPosition.A = new Stack();
			copyPosition.B = new Stack();
			copyPosition.C = new Stack();
			copyPosition.Moves = new List();
			copyPosition.A->operator =(thePosition->A);
			copyPosition.B->operator =(thePosition->B);
			copyPosition.C->operator =(thePosition->C);
			if(thePosition->Moves->head != nullptr) {
				copyPosition.Moves->operator =(thePosition->Moves);
			}
			copyPosition.A->push(copyPosition.C->pop());
			copyPosition.Moves->push(copyPosition.A->top->disk, copyPosition.C, copyPosition.A);
			if(isFound(copyPosition.A, copyPosition.C)) {
				copyPosition.Moves->Print();
				return true;
			}
			else {
				this->enqueue(copyPosition.A, copyPosition.B, copyPosition.C, copyPosition.Moves);
			}
		}
		if(thePosition->B->top == nullptr || thePosition->C->top->disk < thePosition->B->top->disk) {
			copyPosition.A = new Stack();
			copyPosition.B = new Stack();
			copyPosition.C = new Stack();
			copyPosition.Moves = new List();
			copyPosition.A->operator =(thePosition->A);
			copyPosition.B->operator =(thePosition->B);
			copyPosition.C->operator =(thePosition->C);
			if(thePosition->Moves->head != nullptr) {
				copyPosition.Moves->operator =(thePosition->Moves);
			}
			copyPosition.B->push(copyPosition.C->pop());
			copyPosition.Moves->push(copyPosition.B->top->disk, copyPosition.C, copyPosition.B);
			if(isFound(copyPosition.A, copyPosition.C)) {
				copyPosition.Moves->Print();
				return true;
			}
			else {
				this->enqueue(copyPosition.A, copyPosition.B, copyPosition.C, copyPosition.Moves);
			}
		}
	}
	return false;
}

bool Queue::isFound(Stack* A, Stack* C) {
	if(A->top == nullptr && C->top == nullptr) {
		return true;
	}

	return false;
}

bool Queue::checkExists(Stack* A, Stack* B, Stack* C) {
	QUEUE_NODE* frontIterator = front;
	QUEUE_NODE* existIterator = Existed;
	while(frontIterator != nullptr) {
		if(A->operator ==(frontIterator->A) && B->operator ==(frontIterator->B) && C->operator ==(frontIterator->C)) {
			return true;
		}
		frontIterator = frontIterator->next;
	}
	while(existIterator != nullptr) {
		if(A->operator ==(existIterator->A) && B->operator ==(existIterator->B) && C->operator ==(existIterator->C)) {
			return true;
		}
		existIterator = existIterator->next;
	}
	return false;
}

void Queue::deleteExisted(void) {
	QUEUE_NODE* iterator = Existed;

	while(iterator != nullptr) {
		delete iterator->A;
		delete iterator->B;
		delete iterator->C;
		Existed = iterator->next;
		delete iterator;
		iterator = Existed;
	}
}

