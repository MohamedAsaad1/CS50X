#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{// cheack input user
    if (argc != 2)   
    {// printf if user intput Mistake
        printf("Usage: ./caesar key\n"); 
        return 1;
    }
    for (int i = 0 ,   n = strlen(argv[1]) ; i < n; i++)  
    {
        if (!isdigit(argv[1][i]))  
        {
            printf("Usage: ./caesar key\n");  
            return 1;
        }
        
    }
     
     int p = atoi(argv[1]);
        
      string text = get_string("plaintest: ");
        printf ("ciphertext: ");
        for (int i = 0 , text1 = strlen (text); i < text1; i++   )
        
        {
            if (isupper(text[i]))
            
            {
                
                printf("%c",(((text[i] - 65) + p) % 26) + 65 );
            }
            else if (islower(text[i]))
            
            {
                    printf( "%c", (((text[i] - 97) + p) % 26) + 97); 
            }
            
            else 
            {
                printf("%c",text[i]);
            }
        }
            printf("\n");
  
}