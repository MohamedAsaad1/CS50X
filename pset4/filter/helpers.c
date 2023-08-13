#include "helpers.h"
#include <math.h>
#include <stdlib.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
      for(int i =0 ; i < height;i++)
    {
        for(int j=0 ; j < width;j++)
        {
           RGBTRIPLE pix = image[i][j]; 
           
           int aveg =round ((pix.rgbtBlue + pix.rgbtRed+pix.rgbtGreen) /3.0);
           
           
           image[i][j].rgbtBlue = aveg;
           
           image[i][j].rgbtRed = aveg;  
           
           image[i][j].rgbtGreen = aveg;
                              
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
      for(int i =0 ; i < height;i++)
    {
        for(int j=0 ; j < width;j++)
        {
            RGBTRIPLE pix = image[i][j];
             

            //calculate sepia pixels
    int sepiaRed = round(.393 * pix.rgbtRed+ .769 * pix.rgbtGreen + .189 * pix.rgbtBlue);
    int sepiaGreen = round(.349 * pix.rgbtRed + .686 * pix.rgbtGreen + .168 * pix.rgbtBlue);
    int sepiaBlue = round(.272 * pix.rgbtRed + .534 * pix.rgbtGreen + .131 * pix.rgbtBlue);
    
         
          if(sepiaRed > 255)
          {
              image[i][j].rgbtRed =  255;
          }
          else 
          {
              image[i][j].rgbtRed = sepiaRed ;
          }
          
           if(sepiaGreen > 255)
          {
               image[i][j].rgbtGreen =  255;
          }
          else 
          {
               image[i][j].rgbtGreen = sepiaGreen ;
          }
          
             if(sepiaBlue > 255)
          {
              image[i][j].rgbtBlue  =  255;
          }
          else 
          {
              image[i][j].rgbtBlue  = sepiaBlue ;
          }
          
        
         

        }
    }    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    char *copyr = malloc(width+1); 
    char *copyg = malloc(width+1); 
    char *copyb = malloc(width+1); 
    
    for(int i = 0;i <height;i++ )
    {
        for(int j = 0; j<width;j++ )
        {
            copyr[j]=image[i][j].rgbtRed;
            copyg[j]=image[i][j].rgbtGreen;
            copyb[j]=image[i][j].rgbtBlue;
        }
        
        for(int j = 0; j < width;j++ )
        {
            image[i][j].rgbtRed =copyr[width-j-1];
            image[i][j].rgbtGreen =copyg[width-j-1];
            image[i][j].rgbtBlue =copyb[width-j-1];
        }
    }
            
            free(copyr);
            free(copyg);
            free(copyb);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    {
    RGBTRIPLE temp[height][width]; // 

    // For loop to set the value of i
    for (int i = 0; i < height; i++)
    {
      
        for (int j = 0; j < width; j++)
        {
            float counter = 0.0;
            int sumR = 0;
            int sumG = 0;
            int sumB = 0;

            
            for (int c = -1; c < 2; c++)
            {
                for (int v = -1; v < 2; v++)
                {
                    if ((i - c) >= 0 && (i - c) < height && (j - v) >= 0 && (j - v) < width)
                    {
                        sumR = sumR + image[i - c][j - v].rgbtRed; 
                        sumG = sumG + image[i - c][j - v].rgbtGreen;
                        sumB = sumB + image[i - c][j - v].rgbtBlue;
                        counter++; 
                    }
                }
            }

            temp[i][j].rgbtRed = round(sumR/ counter); 
            temp[i][j].rgbtGreen = round(sumG / counter);
            temp[i][j].rgbtBlue = round(sumB / counter);
        }
    }

    //  new loops to switch original values 
    for (int i = 0; i < height - 1; i++)
    {
        for (int j = 0; j < width - 1; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
  }

}