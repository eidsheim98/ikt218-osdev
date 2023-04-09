#include "common.h"
#include "cstdint"
#include "cstddef"

static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}
 
static const size_t VGA_WIDTH = 80; // defalut columns
static const size_t VGA_HEIGHT = 25; // defalut rows
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

void clear_terminal(void) 
{
	terminal_row = 0;  // start in the upper left corner in the canvas/terminal
	terminal_column = 0; // start in the upper left corner
	terminal_color = 7;     // 7 = VGA_COLOR_LIGHT_GREY
	terminal_buffer = (uint16_t*) 0xB8000;  // VGA text mode buffer 
	for (size_t y = 0; y < VGA_HEIGHT; y++) {   // looping through terminal window 
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x; // find cursor position 
			terminal_buffer[index] = vga_entry(' ', terminal_color); // coloring 
		}
	}
}

void write_to_terminal(int row, char word[80])
{
    uint8_t (*fb)[80][2] = (uint8_t (*)[80][2]) 0xb8000; // The text screen video memory for colour monitors

    int wordlen = 0;

    while(word[wordlen] != '\0' ){
        wordlen++; // set wordlength
    }

    for(int i = 0; i < wordlen; i++){
        fb[row][i][0] = word[i]; // first parameter: row, second: column, third: color.
    }
}

void write_int_to_terminal(int row, u32int n)
{

    if (n == 0)
    {
        write_int_to_terminal(row, '0');
        return;
    }

    s32int acc = n;
    char c[32];
    int i = 0;
    while (acc > 0)
    {
        c[i] = '0' + acc%10;
        acc /= 10;
        i++;
    }
    c[i] = 0;

    char c2[32];
    c2[i--] = 0;
    int j = 0;
    while(i >= 0)
    {
        c2[i--] = c[j++];
    }
    write_to_terminal(row, c2);

}

void print_logo() {

write_to_terminal(3,"                         _________ _______    _______  _______");
write_to_terminal(4,"                |\\     /|\\__   __/(  ___  )  (  ___  )(  ____ \\");
write_to_terminal(5,"                | )   ( |   ) (   | (   ) |  | (   ) || (    \\/");
write_to_terminal(6,"                | |   | |   | |   | (___) |  | |   | || (_____ ");
write_to_terminal(7,"                | |   | |   | |   |  ___  |  | |   | |(_____  )");
write_to_terminal(8,"                | |   | |   | |   | (   ) |  | |   | |      ) |");
write_to_terminal(9,"                | (___) |___) (___| )   ( |  | (___) |/\\____) |");
write_to_terminal(10,"                (_______)\\_______/|/     \\|  (_______)\\_______)");
write_to_terminal(12,"            By Markus Hagli, Charlotte Thorjussen, Nikolai Eidsheim");
}