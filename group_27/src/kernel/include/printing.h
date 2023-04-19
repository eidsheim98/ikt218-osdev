#ifndef PRINTING_H
#define PRINTING_H

#include "common.h"
#include "cstdint"
#include "cstddef"

static inline uint16_t vga_entry(unsigned char uc, uint8_t color);
 
static const size_t VGA_WIDTH = 80; // defalut columns
static const size_t VGA_HEIGHT = 25; // defalut rows

void clear_terminal(void);

void print(char word[80]);


void print_logo();

#endif