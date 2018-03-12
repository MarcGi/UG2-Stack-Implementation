/* Marc Giannandrea | AC21008 
stack_tester.c
Used to test the stack data structure made with various test cases
*/

#include <stdbool.h>
#include "stack.h"
#include <stdio.h>


/* Iterate from 'nextF' printing datas as we go. */
// Adapated from code from stack_tester.c
void printStack(Stack *stk)
{
	Frame* nextF = stk->head;
	while(nextF != NULL) {
		printf(" %d ->", nextF->data);
		nextF = nextF->next;
	}
	printf(" %p\n", (Frame*)nextF);
}


/* Print out all details for 'f'. */

/* Basic testing for Frame. */
int main()
{
	Stack* newStk = createStack();
	//Test for init of stack values.
	printStack(newStk);
	
	//Test for Push
	push(newStk,4);
    push(newStk,8);
    push(newStk,8);
	printStack(newStk);

	//Test for Pop
	pop(newStk);
	pop(newStk);
	pop(newStk);
	
	// Push and then pop
	push(newStk,5);
	pop(newStk);
	printStack(newStk);
	
	//Push onto stack
	push(newStk,6);
	printStack(newStk);

	//Pop beyond stack size test
    pop(newStk);
    pop(newStk);
    pop(newStk);
	printStack(newStk);

	//printf("Finished test.\n");
	releaseStack(newStk);
	newStk = NULL;

	//Push onto non existing stack
	push(newStk,100);
	
	//Pop from non existing stack
	pop(newStk);

	
	return 0;
}

