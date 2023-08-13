 #include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)

{
    string s = get_string("Text: ");
     
    int l = 0;
    
    int g = 0;
    
    int w = 1;
    // counter
    for ( int i = 0 ,c = strlen(s); i < c; i++  )   
    
    {
        if (isalpha(s[i]))
        
         {
            
        l++;
        
         }
        
        else if ( s[i] == '!'|| s[i] == '.' || s[i] == '?' )
        
         {
            g++;
         }
        
      else if ( s[i]  ==  ' ' )
        
         {
             w++;
         }
    }    
    
    // clculate 
    float f = 0.0588 * (100 * (float) l / (float) w ) - 0.296 * (100 * (float) g / (float) w ) - 15.8;
    if ( f < 16 && f >= 0)
    
    //printf
    {

        printf("Grade %i\n", (int) round(f));
    }
    else if ( f >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}
