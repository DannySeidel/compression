#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <zlib.h>

#define BUFFER 1024

char *readFile(char *text) {
    FILE *fp = fopen("test.txt", "r");

    if (fp == NULL) {
        perror("file not found");
        exit(-1);
    }

    fgets(text, BUFFER, fp);

    fclose(fp);

    return text;
}


char *compressText(char *text, char *compressedText) {

    printf("Uncompressed string is: %s\n", text);

    z_stream defstream;
    defstream.zalloc = Z_NULL;
    defstream.zfree = Z_NULL;
    defstream.opaque = Z_NULL;
    defstream.avail_in = (uInt) strlen(text) + 1; // size of input, string + terminator
    defstream.next_in = (Bytef *) text; // input char array
    defstream.avail_out = (uInt) sizeof(compressedText); // size of output
    defstream.next_out = (Bytef *) compressedText; // output char array

    // the actual compression work.
    deflateInit(&defstream, Z_BEST_COMPRESSION);
    deflate(&defstream, Z_FINISH);
    deflateEnd(&defstream);

    printf("Compressed string is: %s\n", compressedText);

    return compressedText;
}

void decompressText(char *text) {
    char decompressedText[BUFFER];

    z_stream defstream;
    z_stream infstream;
    infstream.zalloc = Z_NULL;
    infstream.zfree = Z_NULL;
    infstream.opaque = Z_NULL;
    infstream.avail_in = (uInt) ((char *) defstream.next_out - text); // size of input
    infstream.next_in = (Bytef *) text; // input char array
    infstream.avail_out = (uInt) sizeof(decompressedText); // size of output
    infstream.next_out = (Bytef *) decompressedText; // output char array

    // the actual DE-compression work.
    inflateInit(&infstream);
    inflate(&infstream, Z_NO_FLUSH);
    inflateEnd(&infstream);

    printf("Uncompressed string is: %s\n", decompressedText);

}

int main() {
    char text[BUFFER] = "Hello Test. Hello Test. Hello Test!";

    char compressedText[BUFFER];
    char *cmp = compressText(text, compressedText);
    decompressText(cmp);

    return 0;
}