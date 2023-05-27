#include "printing.h"
#include "system.h"

char buffer[80] = {0};
int bufLen = 0;

void increaseBuffer(char c) {
    buffer[bufLen] = c;
    bufLen += 1;
}

void decreaseBuffer() {
    buffer[bufLen] = '\0';
    bufLen -= 1;
}

char getBuffer() {
    return *buffer;
}

char resetBuffer() {
    bufLen = 0;
    mymemset(buffer, 0, 80);
}

void runCommand() {
    if (strcmp(buffer, "test") == 0) {
        // This will only run once because the buffer is never reset because of memory stuff
        print("\nYay!");
    }
    else if (strcmp(buffer, "help") == 0) {
        // This will only run once because the buffer is never reset because of memory stuff
        print("\ntest");
        print("\npepsi");
        print("\nakira");
    }
    else if (strcmp(buffer, "pepsi") == 0) {
        // This will only run once because the buffer is never reset because of memory stuff
        print("\ner kul");
    }
    else if (strcmp(buffer, "akira") == 0) {
        // This will only run once because the buffer is never reset because of memory stuff
        print("\ner søt");
    }
    else {
        print("\nCommand not found: ");
        print("\n");
        print(buffer);
    }
    resetBuffer();
}