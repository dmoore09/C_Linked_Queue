//Daniel Moore
////905614004
////
////On my honor:
////
////I have not discussed the C language code in my program with
////anyone other than my instructor or the teaching assistants assigned to this course.
////
////I have not used C language code obtained from another student, or
////any other unauthorized source, either modified or unmodified.
////If any C language code or documentation used in my program
////was obtained from another source, such as a text book or course
////notes, that has been clearly noted with a proper citation in the comments of my program.
////
////<Daniel Moore>
//
#include "IntegerQueue.h"
#include "Queue.h"
#include <stdlib.h>
#include "IntegerDT.h"

//initialize IntegerQueue
void IntegerQueue_Init(IntegerQueue* const pIQ){
	Queue_Init(&((*pIQ).Q));
}

//true if empty
bool IntegerQueue_Empty(const IntegerQueue* const pIQ){
	return Queue_Empty((&(*pIQ).Q));
}

// Insert K at rear of IntegerQueue
void IntegerQueue_Push(IntegerQueue* const pIQ, int32_t K){
	IntegerDT *wrapper = malloc(sizeof(IntegerDT));
	IntegerDT_Init(wrapper, K);
	Queue_Push(&(pIQ->Q), &(wrapper->node));
}

// Remove and return data value from front of IntegerQueue
int32_t IntegerQueue_Pop(IntegerQueue* const pI){
	QNode* node = Queue_Pop(&(pI->Q));
	IntegerDT *p = Queue_Entry(node, IntegerDT, node);
	int payload = p->payload;
	free(p);
	return payload;
}


