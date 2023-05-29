/*
 * This is a header file for a simple memory management library.
 * It includes declarations for functions related to memory allocation,
 * paging and memory manipulation (copying and setting).
 */

#ifndef PAGING_H
#define PAGING_H

#include <stdint.h> /* Include standard integer types */
#include <stddef.h> /* Include standard definitions */

/* Function declarations for paging operations */
extern void init_paging(); /* Initializes paging */
extern void paging_map_virtual_to_phys(uint32_t virt, uint32_t phys); /* Maps a virtual address to a physical address */

#endif