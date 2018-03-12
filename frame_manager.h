/*
Marc Giannandrea | AC21008 
frame_manager.h | Header File For Function Prototype Definitions
*/
#include "frame.h"

//Definition of function prototypes
Frame* getFrame(); // Return a pointer to a Frame that it will create
void releaseFrame(Frame* passedFrame); //Takes a pointer to a frame and then frees the Frame from memory whilst also nulling it

