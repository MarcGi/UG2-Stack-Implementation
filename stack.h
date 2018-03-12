/*
Marc Giannandrea | AC21008 
stack.h | Header File For Function Prototype Definitions Used By stack.c
*/
#include "frame_manager.h"

//Definition of stack structure
typedef struct myStack {
    int size;
    Frame* head;
}Stack;

//Definition of function prototypes
Stack* createStack();
bool isEmpty(Stack* stk); //Takes a stack in and returns a bool if empty
void push(Stack* stk, int x); //Takes in a stack and an int. Adds them to stack.
int pop(Stack* stk); //Takes in a stack and removes the head of the stack and return the data as an int.
void releaseStack(Stack* stk); // Takes in a stack and releases it from memory whilst also setting its values to null


