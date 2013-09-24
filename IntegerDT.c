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

#include "IntegerDT.h"

// Insert K into payload field and set node pointers to NULL
void IntegerDT_Init(IntegerDT* const pDT, int32_t K)
{
	//insert payload
	(*pDT).payload = K;

	//set pointers to null
	(*pDT).node.next = NULL;
	(*pDT).node.prev = NULL;
}
