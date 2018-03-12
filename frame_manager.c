/*
Marc Giannandrea | AC21008
frame_manager.c | C Source file containing getFrame and releaseFrame in order to add or remove Frames
*/

#include <stdlib.h>
#include "frame_manager.h"


Frame* getFrame(){
    Frame* ptrFrame;
    
    //Put ptrFrame into non volatile
    ptrFrame = malloc(sizeof(Frame));
    return (ptrFrame);
}


void releaseFrame(Frame *passedFrame){
    free(passedFrame);//Free the passed frame from memory

    //Set the data in the frame to null to prevent other programs from accessing the data.
    passedFrame->next = NULL;
    passedFrame = NULL;
  }
