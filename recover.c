#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage:./recover IMAGE\n");
        return 1;
    }
    //I am extremely hungry right now, I shouldnt be allowed to code
    // if there is an error during, return error message
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file");
        return 2;
    }
    //Open Memory Card
    //Repeat until the end of the card
    //read 512 bytes
    // if start of a new JPEG yay, keep it
    //if not close the fiile
    unsigned char buffer[512];
    int file_count = 0;
    char *filename = malloc(8 * sizeof(char));//OR? char filename[8] because xxx.jpg'\0'
    FILE *output_file = NULL;

    // FILE *f = fopen(filename, "r"); //read mode
    //jpeg files start with 0xff 0xd8 0xff 0xe?
    //start checking bytes that begin with 0xff ...., if, we find and other byte starts with the sequence, we should close the previous one, its a new jpeg file
    //buffer3 is a bit tricky here, ı put paranthesis like this then worked (buffer[3] & 0xf0)
    while (fread(buffer, sizeof(char), 512, input_file)) //== BLOCK_SIZE
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0) //last one says, just look at the first 4 bits and set the remaining to zero
        {
            sprintf(filename, "%03i.jpg", file_count); //create filename
            output_file = fopen(filename, "w"); //open file DONOT USE THIS LIKE A POINTER CAUSE IT DOESNT COMPILE :p
            file_count++;
            //use fread

        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    free(filename);
    fclose(output_file);
    fclose(input_file);
    return 0;
    // dont forget to close everything
}