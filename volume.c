// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }
    // fopen: Opens the file whose name is specified in the parameter filename and associates it with a stream that can be identified in future operations by the FILE pointer returned. The operations that are allowed on the stream and how these are performed are defined by the mode parameter.

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    // atof: The atof() function ignores all the leading whitespace characters until the primary non-whitespace character is found. Then, beginning from this character, it takes as many characters as possible that forms a valid floating-point representation and converts them to a floating point value.

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    //size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
    //size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);

    uint8_t header[HEADER_SIZE]; // we create an uint called header
    fread(header, HEADER_SIZE, 1, input);
    // header = This is the pointer to a block of memory with a minimum size of size*nmemb bytes
    // HEADER_SIZE = This is the size in bytes of each element to be read. Constant int equal to 44
    // 1 = This is the number of elements, each one with a size of size bytes.
    // input = This is the pointer to a FILE object that specifies an input stream.

    fwrite(header, HEADER_SIZE, 1, output);
    // fread and fwrite are like the copy paste?

    // TODO: Read samples from input file and write updated data to output file
    int16_t buffer; //here we created the int called buffer
    // use while loop to go through every byte?
    while (fread(&buffer, sizeof(int16_t), 1, input)) // has to put the & for the address
    {
        buffer *= factor; //line 36, it is one of our arguments in int main.
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    // Close files
    fclose(input);
    fclose(output);
}
