#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    char* arguments[4];         //make an array that can hold up to 4 strings
    arguments[0]="./countprimes";   //the first string is the command name
    arguments[1]=argv[1];          //the second and third strings are the start and end parameters
    arguments[2]=argv[2];
    arguments[3]=NULL;          //the last argument must be a null terminator
    int k=0;
    int i=0;
    int processid;
    int NUMBER_OF_CALLS = atoi(argv[3]);
    int processids[NUMBER_OF_CALLS];
    int total;
    int status;
    int min = atoi(arguments[1]);
    int max = atoi(arguments[2]);
    int inc = atoi(arguments[2])-atoi(arguments[1]);
    int range = (max-min)/NUMBER_OF_CALLS;
    int increment[NUMBER_OF_CALLS+1];
    int counter;
    increment[0] = atoi(arguments[1]);
    /*While loops that checks if the range  with variables doesnt divide evenly then adds to counter and subtracts from the increment*/ 
    while(inc % NUMBER_OF_CALLS != 0)
    {
            counter += 1;
            inc -= 1;
    }
    
    for(i=0; i< NUMBER_OF_CALLS; i++)
    {
            if(i+1<NUMBER_OF_CALLS)
            {
                min += inc / NUMBER_OF_CALLS;
                increment[i+1]= min;
            }
            else
            {
                increment[i+1]= min+counter+inc / NUMBER_OF_CALLS;
                min += counter;
            }
    }

    for(i=0; i < NUMBER_OF_CALLS; i++)
    {
            processids[i] = fork();
            if(processids[i] == 0)
            {
                    char sstr[50];
                    char estr[50];
                    sprintf(sstr, "%d", increment[i]);
                    sprintf(estr, "%d", increment[i+1]);
                    arguments[1]=sstr;
                    arguments[2]=estr;
                    execvp("./countprimes",arguments);  //call the countprimes child program
                    printf("Called after execvp\n");
            }
    }

    for(k=0; k<NUMBER_OF_CALLS; i++)
    {
        waitpid(processids[k], &status, 0);
    /*printf("This was not process 0\n");*/
       /* printf("Exit status: %d\n", exitStatus);*/
        total += WEXITSTATUS(status);
        if(k== NUMBER_OF_CALLS-1)
        {
            printf("Total: %d\n", total);
        }   
    }
}
