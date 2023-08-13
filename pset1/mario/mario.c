#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
    do
    {
        x = get_int("Height: "); // user in put
    }
    while ((x < 1) || (x > 8));

    for (int i = 0; i < x ; i++)
    {
        for (int k = 0; k < x; k++)
         
        {
            if (i + k < x - 1) 
            
                printf(" ");//printf space
                
                else  
                
                    printf("#");//printf hash
                    
            
                }
                printf("\n");// printf new line
                   

            }
    
    
    
        }


for(int i = 0; i < 4; i++){
        for(int k =0; k < number; k++ ){
            printf("*");
        }
        printf("\n");
        number = number -2;
        for(int j = 0; j < i; j++){
            printf(" ");
        }
        
       
    }