/*
Marc Giannandrea | AC21008 
stack.c | C Source file containing every function relevant to the stack data structure implementation
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"


Stack* createStack(){
    //Create a new stack in non volatile memory
    Stack* newStk = malloc(sizeof(Stack));
    if(newStk){
        //Initialise stack variables
        newStk->size = 0;
        newStk->head = NULL;

        printf("Stack has been created\n"); 
        return newStk;
    }else{
         printf("Error: Malloc failed\n"); 
        return NULL;
    }
}

void releaseStack(Stack* stk){
    if(!stk){
        //If stck is null then
        printf("Error: Unable to release stack. Stack is NULL\n");
    }else{
        //Go through all of items in the stack and pop them
        for(int i = 0; i < stk->size; i++){
              pop(stk);  
        }
        //Then free the stack from memory
        free(stk);
        stk = 0;
        
        printf("Stack has been released\n");
    }
    
}

bool isEmpty(Stack* stk){
    if(!stk){
        // If stk is null then
        printf("Error: Failed to check if stack is empty. Stack is NULL\n");
        return true;
    }else{
        if(stk->size == 0){
            return true;
        }else{
            return false;
        }
    }
}

void push(Stack* stk, int x){
    if(!stk){
        printf("Error: Failed to push to stack. Stack is NULL\n");
        return;
    }else{
        //Request new frame to add onto stack
        Frame* newFrame = getFrame();

        // Add the relevant data to the frame
        newFrame->data = x;
        
        //Set the newFrame as head
        newFrame->next = stk->head;
        stk->head = newFrame;

        //Increase the stack size
        stk->size = stk->size + 1;
        printf("Pushed %d to stack.\n",x);
    }     
}

int pop(Stack* stk){
    if(!stk){
        printf("Error: Unable to pop. Stack is NULL. Returning Error : -999\n");
        return -999;
    }else{
        //If the stack is empty then return -999 as an error integer
        if(isEmpty(stk)){
            printf("Error: Stack Is Empty. Unable to pop. Returning Error : -998\n");
            return -998;
        }else{
                //Get the (void*)head of the stacks data
                int data = stk->head->data;
                
                //SetUp temp variable to store the head of the stack
                Frame* toRel =  stk->head;

                //Set the head of the stack to the next frame in the stack
                stk->head = stk->head->next;

                //Release/remove the frame
                releaseFrame(toRel);

                //Decrease the stack size
                stk->size = stk->size - 1;

                printf("Popped %d from stack.\n", data);
                return data;
        }
    }
    
}

