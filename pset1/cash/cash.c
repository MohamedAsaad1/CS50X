#include <cs50.h>  
#include <stdio.h>  
#include <math.h>
int main(void) 

{
    float x;
    do
    {
        x = get_float("change owed: ");  // user owed
     
    }
    while (x < 0);//loop for  convert to Cents
  
    int z = round(x );
    int c = 0;
  
    while (z >= 25) //loop for quaters
    {
        z = z - 25;
        c++;
    }
    //loop for nicles
    while (z >= 10)
    {
        z = z - 10;
        c++;
    }
    while (z >= 5)//loop for pennies
    {
        z = z - 5;
        c++;
    }
    while (z >= 1 || z > 0)
     
    {
        z = z - 1;
    
        c++;
        
     
    }
    //printing total  coins
    printf("%i\n", c);
 
}