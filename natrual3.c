#include <stdio.h>
void sum(int n, int*answer) /*initializes the sum function to be used with direct console input*/
{
    int inc, total; /*initializes variables for natrual number summation*/
    total=0; 
   /* printf("Enter a positive integer: ");
    scanf("%d", &n);*/
    inc =1;
    while(inc<=n){ /*while loop that runs until counter is less than or equal to the desired natrual num */
        total+=inc;
        ++inc;
    }
    printf("Total = %d", total); /* prints the answer*/
    *answer= total; /*sets answer equal to total*/
}
int main(int argc, char* argv[]){ /*main function that takes an integer and direct console input*/
  /* printf("Hello World"); prints hello world for part 1 of assignment*/

   int env_x = atoi(argv[1]); /*sets  n to a integer value from a string in the array of arguments*/
   int ans;
   sum(env_x, &ans);/*calls the function and computes it with n as an integer and gets the answer variable*/
}


