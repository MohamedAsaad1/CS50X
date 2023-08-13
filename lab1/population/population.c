#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompt for start size
    int start = 0;
    do 
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
 
    //  Prompt for end size
   
    int end = 0;
    do 
    {
        end = get_int("End size: ");
    }
    while (end < start);
  
    //  Calculate number of years until we reach 
    int years = 0;
    
    while (start < end)
    {
        start += (start / 3) - (start / 4); 
        years++;
    }   
    
    // Print number of years
    
    printf("Years: %i\n", years);
}