#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image");
        return 1;
    }
     char *file =argv[1];


    FILE *input = fopen(file, "r");
    //if check Input_file pointer fail to open then REturn error code "Could not open file"
    if (input == NULL)
    {
        printf("Usage:couldn't open the card ");
        return 1;
    }

    //declare a variable to unsigned char to store 512 chunks array
     BYTE open[512];

    //for the purpose of counting of image later in the loop
    int count = 0;

    //An uninitialize file pointer to use to output data gotten from input file
    FILE *output = NULL;

    char *file1 = malloc(8 * sizeof(BYTE));
    //char filename[8];

    /*Read 512 bytes from input_file and store on the buffer*/
    while (fread(open, sizeof(char), 512, input))
    {
        //check if bytes is start of a JPEG
        if (open[0] == 0xff && open[1] == 0xd8 && open[2] == 0xff && (open[3] & 0xf0) == 0xe0)
        {
            //write jpeg into file name in form 001.jpg, 002.jpg and so on
            sprintf(file1, "%03i.jpg", count);

            //open Out_file for writing
            output = fopen(file1, "w");

            //fwrite(buffer, sizeof(buffer), 1, output_file);
            //count number of image found
            count++;
        }
        //Check if output have been used for valid input
        if (output != NULL)
        {
            fwrite(open, sizeof(char), 512, output);
        }

    }
    free(file1);
    fclose(output);
    fclose(input);

    return 0;
}

