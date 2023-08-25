#include <stdio.h>
#include <stdlib.h>
#include <time.h> // needed for the usual srand() initialization
#include <string.h>

#define MAX_LINES 6
#define MAX_LENGTH 30


int main(void)
{
    FILE *fptr;  
    char string_table[MAX_LINES][MAX_LENGTH];
    char buffer[MAX_LENGTH];
    int line_count = 0;

    // Open a file in read mode  
    fptr = fopen("test.txt", "r");  
  

    if(fptr != NULL) 
    {  
        // Read each line and copy it into the array
        while (fgets(buffer, MAX_LENGTH, fptr) != NULL) 
        {
            // Remove the newline character, if present
            if (buffer[strlen(buffer) - 1] == '\n')
            {
                buffer[strlen(buffer) - 1] = '\0';
            }

            // Copy the line into the array
            strcpy(string_table[line_count], buffer);
            line_count++;

            // Check if the array is full
            if (line_count >= MAX_LINES) 
            {
                break;
            }
        }

        srand(time(NULL)); // randomize the start value. 
         //The C library function void srand(unsigned int seed) seeds the random number generator used by the function rand.

        for (int i = 0; i <= 1; ++i)
        {

            const char *rand_string = string_table[rand() % MAX_LINES];
            printf("%s\n",  rand_string);
        }

        
    } 

    else 
    {  
        printf("Not able to open the file.");  
    }     
  
    // Close the file  
    fclose(fptr);

    return 0;
}