#ifndef MEMORY_H
#define MEMORY_H

char *mymemset (char *s, int v, size_t n);
void init_kernel_memory(uint32_t* kernel_end);

#endif