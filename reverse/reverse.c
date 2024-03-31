#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse ./reverse input.wav output.wav\n");
        return 1;
    }

    char *infile = argv[1];

    // Open input file for reading
    FILE *i = fopen(infile, "r");
    if (i == NULL)
    {
        printf("Error: cannot open %s\n", infile);
        return 1;
    }

    // Read header
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, i);

    // Use check_format to ensure WAV format
    if (check_format(header) == 0)
    {
        printf("Not a wav file\n");
        return 1;
    }

    if (header.audioFormat != 1)
    {
        printf("Not a wav file\n");
        return 1;
    }

    // Open output file for writing
    char *outfile = argv[2];
    FILE *o = fopen(outfile, "w");
    if (o == NULL)
    {
        printf("Error: cannot open %s\n", outfile);
        return 1;
    }

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, o);

    // Use get_block_size to calculate size of block
    int size = get_block_size(header);

    // Write reversed audio to file
    if (fseek(i, size, SEEK_END))
    {
        return 1;
    }
    BYTE buffer[size];
    while (ftell(i) - size > sizeof(header))
    {
        if (fseek(i, -2 * size, SEEK_CUR))
        {
            return 1;
        }
        fread(buffer, size, 1, i);
        fwrite(buffer, size, 1, o);
    }

    fclose(o);
    fclose(i);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 87 && header.format[1] == 65 && header.format[2] == 86 && header.format[3] == 69)
        return 1;
    else
        return 0;
}

int get_block_size(WAVHEADER header)
{
    int size = header.numChannels * header.bitsPerSample / 8;
    return size;
}