/*
 * List.cpp
 *
 *  Created on: Feb 25, 2019
 *      Author: kennethpadron
 */

#include "List.h"

List::List() {
	// TODO Auto-generated constructor stub
	head = nullptr;
	numMoves = 0;
}

List::~List() {
	// TODO Auto-generated destructor stub
	init();
}

void List::push(int Disk, Stack *From, Stack *To) {
	Move *nextMove = new Move();
	Move* iterator = head;
	nextMove->disk = Disk;
	nextMove->from = From;
	nextMove->to = To;
	nextMove->next = nullptr;

	if(head == nullptr) {
		head = nextMove;
	}
	else {

		while(iterator->next != nullptr) {
			iterator = iterator->next;
		}
		iterator->next = nextMove;
	}
	numMoves++;
}

void List::Print(void) {
	Move* iterator = head;
	int count = 1;
	while(iterator != nullptr) {
		cout << "Move " << count << ": " << endl;
		cout << setw(4) << "Disk" << setw(8) << "From" << setw(8) << "To" << endl;
		cout << setw(4) << iterator->disk << setw(8) << iterator->from->name << setw(8) << iterator->to->name << endl << endl;
		count++;
		iterator = iterator->next;
	}

}

void List::init(void)
{
    Move *p = head;
    while(p)
    {
        p = p->next;
        delete head;
        head = p;
    }
    return;
}

void List::operator=(List* copy) {
	if(copy->head != nullptr) {
		this->head = new Move;
		Move* copyIterator = copy->head;
		Move* thisIterator = this->head;
		while(copyIterator->next != nullptr) {
			thisIterator->next = new Move;
			thisIterator->disk = copyIterator->disk;
			thisIterator->from = new Stack();
			thisIterator->to = new Stack();
			thisIterator->from->operator =(copyIterator->from);
			thisIterator->to->operator =(copyIterator->to);
			thisIterator = thisIterator->next;
			copyIterator = copyIterator->next;
		}
		thisIterator->from = new Stack();
		thisIterator->to = new Stack();
		thisIterator->from->operator =(copyIterator->from);
		thisIterator->to->operator =(copyIterator->to);
		thisIterator->disk = copyIterator->disk;
		thisIterator->next = nullptr;
		this->numMoves = copy->numMoves;
	}
	else {
		this->head = nullptr;
		this->numMoves = 0;
	}

}
