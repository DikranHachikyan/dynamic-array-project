/* 
 * File:   main.c
 * Author: wizard
 *
 * Created on 30 June 2013, 4:28 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "inc/darray.h"
#include "inc/io.h"

/*
 * 
 */
enum {
    PUSH = 1,
    POP,
    UNSHIFT,
    SHIFT,
    STRINS,
    PRINT,
    EXIT
};
int main(int argc, char** argv) {
    Array *arr = NULL;
    int opt = 0;
    int t,res;
    arr = createArray();
    assert(arr != NULL);
    for(;;){

        fprintf(stdout, "\n%d-push,%d-pop,     %d-unshift,%d-shift,%d-sraightInsert,%d-print,%d-exit:",
                            POP, UNSHIFT, SHIFT, PUSH,  STRINS, PRINT, EXIT);
        fprintf(stdout, "\n%d-push,%d-pop,     %d-unshift, %d-shift,%d-sraightInsert,%d-print,%d-exit:",
                            SHIFT, STRINS, PRINT, EXIT, PUSH, POP, UNSHIFT);
        fprintf(stdout, "\n%d-push,%d-pop,%d-unshift,   %d-shift,%d-sraightInsert,%d-print,%d-exit:",
                            PUSH, POP, SHIFT, STRINS, PRINT, EXIT, UNSHIFT);
        scanf("%d",&opt);
      
            if (opt == POP)
             {           res = pop(arr,&t);
                        if(res == -1)
                        {
                          fprintf(stdout,"The array is empty!");
                        }                        
                        else
                        {
                          fprintf(stdout,"item:%d poped!\n ",t);
                        }
              }
            switch(opt)
            {
            case UNSHIFT: t = rand() % 100;
                          unshift(arr,t);
                          fprintf(stdout,"item:%d unshifted!\n",t);
                          break;
            case PUSH:  t = rand()% 100;
                        push(arr,t);
                        fprintf(stdout,"item:%d pushed!\n",t);
                        break;
            case SHIFT: res = shift(arr, &t); 
                        if( res != -1)
                          {
                            fprintf(stdout, "item:%d shifted!\n",t);
                          }
                        else
                          {
                            fprintf(stdout, "The array is empty\n");
                          }
                        break;
            case STRINS: straightInsertion(arr);
                         break;
            case SAVE:  saveToFile( "data", arr );
                        break;
            case PRINT: print(arr);
                        break;
            case EXIT: destroy(arr);
                        exit(0);
        }
    }
    return (EXIT_SUCCESS);
}

