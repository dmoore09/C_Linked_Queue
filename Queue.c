//Daniel Moore
//905614004
//
//On my honor:
//
//I have not discussed the C language code in my program with
//anyone other than my instructor or the teaching assistants assigned to this course.
//
//I have not used C language code obtained from another student, or
//any other unauthorized source, either modified or unmodified.
//If any C language code or documentation used in my program
//was obtained from another source, such as a text book or course
//notes, that has been clearly noted with a proper citation in the comments of my program.
//
//<Daniel Moore>

// Initialize QNode pointers to null
#include "Queue.h"

void QNode_Init(QNode* pN){
	//dereference and set to null
	(*pN).next = NULL;
	(*pN).prev = NULL;
}

// Initialize Queue to empty state
void Queue_Init(Queue* pQ){

	//front points to tail
	(*pQ).front.next = &((*pQ).rear);
	//tail prev points to front
	(*pQ).rear.prev = &((*pQ).front);

	//others set to null
	(*pQ).front.prev = NULL;
	(*pQ).rear.next = NULL;
}

// Return whether Queue is empty
bool Queue_Empty(const Queue* const pQ){

	//return true if empty
	if ((*pQ).front.next == &((*pQ).rear)){
		return true;
	}
	else{
		return false;
	}
}

// Insert *pNode as last interior element of Queue
void Queue_Push(Queue* const pQ, QNode* const pNode){
	
	//new node has next as tail, tail has previous as new
	(*pNode).next = &((*pQ).rear);
	//pNode previous is tails prev
	(*pNode).prev = (*pQ).rear.prev;
	//tails prev's next is now pNode
	QNode* change = (*pQ).rear.prev;
	(*change).next = pNode;
	//tail's prev is pNode
	(*pQ).rear.prev = pNode;
}

// Remove first interior element of Queue and return it
QNode* const Queue_Pop(Queue* const pQ){
	//check for empty queue
	if (Queue_Empty(pQ)){
		return NULL;
	}
	
	QNode* popVal = (*pQ).front.next;
	//make front point to node after next
	QNode* afterNext = (*pQ).front.next;
	(*pQ).front.next = (*afterNext).next;
	QNode* change = (*pQ).front.next;
	(*change).prev = &((*pQ).front);
	//return front value
	return popVal;
}

// Return first interior element, if any
QNode* const Queue_Front(Queue* const pQ){
		
	if (Queue_Empty(pQ)){
		return NULL;
	}
	return (*pQ).front.next;
}

// Return last interior element, if any
QNode* const Queue_Back(Queue* const pQ){
	 if (Queue_Empty(pQ)){
                return NULL;
        }
	
	return (*pQ).rear.prev;
	
}
