/*
 * Stack.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: kennethpadron
 */

#include "Stack.h"
#include  <iostream>
using namespace std;


Stack::Stack()
{
	// TODO Auto-generated constructor stub
	top = nullptr;
	bottom = nullptr;
	numDisks = 0;
	name = ' ';
}

Stack::~Stack()
{
	// TODO Auto-generated destructor stub
	init();
}

void Stack::push( int n )
{
    STACK_NODE *e = new STACK_NODE;
    e->disk = n;
    if(top == nullptr) {
    	bottom = e;
    }
    e->next = top;
    top = e;

    numDisks++;
    return;
}

// return a pointer to the top element without removing it
int Stack::peek() const
{
    if( !top )
    {
        cout << "Fatal peek() error - stack is empty" << endl;
        exit( -2 );
    }
    return top->disk;
}

// remove and return the top element if there
int Stack::pop()
{
    STACK_NODE *p = top;
    int n;
    if( top == nullptr )
    {
        cout << "Fatal error -- pop from empty stack!" << endl;
        exit( -1 );
    }

    if( top != nullptr ) // Why?
    {
        top = top->next;
    }
    n = p->disk;

   // delete p;
    numDisks--;

    return n;
}

// clean out stack, returning all memory to system heap
void Stack::init()
{
    STACK_NODE *p = top;
    while( p )
    {
        p = p->next;
        delete top;
        top = p;
    }
    return;
}

// returns true if stack is empty, else false
bool Stack::IsEmpty()
{
    return top == nullptr; // !top
}

//bool Stack::operator!=(Stack theStack) {
//	STACK_NODE *iteratorThis = top;
//	STACK_NODE *iteratorTheStack = theStack.top;
//
//	for(int i = 0; i < theStack.numDisks; i++) {
//		if(iteratorTheStack->disk != iteratorThis->disk) {
//			return true;
//		}
//		else {
//			iteratorTheStack = iteratorTheStack->next;
//			iteratorThis = iteratorThis->next;
//		}
//	}
//	return false;
//}

void Stack::operator=(Stack* copy) {
	if(copy->top != nullptr) {
		this->top = new STACK_NODE;
		STACK_NODE* copyIterator = copy->top;
		STACK_NODE* thisIterator = this->top;
		while(copyIterator->next != nullptr) {
			thisIterator->next = new STACK_NODE;
			thisIterator->disk = copyIterator->disk;
			thisIterator = thisIterator->next;
			copyIterator = copyIterator->next;
		}
		thisIterator->disk = copyIterator->disk;
		thisIterator->next = nullptr;
		this->bottom = thisIterator;
		this->name = copy->name;
		this->numDisks = copy->numDisks;
	}
	else {
		this->top = nullptr;
		this->bottom = nullptr;
		this->name = copy->name;
		this->numDisks = copy->numDisks;
	}

}

bool Stack::operator==(Stack* theStack) {
	if(theStack->numDisks != this->numDisks) {
		return false;
	}
	else if(theStack->numDisks == 0) {
		return true;
	}
	STACK_NODE* thisIterator = this->top;
	STACK_NODE* theStackIterator = theStack->top;

	for(int i = 0; i < theStack->numDisks; i++) {
		if(thisIterator->disk != theStackIterator->disk) {
			return false;
		}
		else {
			thisIterator = thisIterator->next;
			theStackIterator = theStackIterator->next;
		}
	}
	return true;
}
