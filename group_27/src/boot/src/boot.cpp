#include "boot.h"
#include "system.h"

extern void monitor_initialize();


extern "C" {
    void init_multiboot(uint32_t magic /*eax*/, multiboot_info* info /*ebx*/);
};


void init_multiboot(uint32_t magic /*eax*/, multiboot_info* info /*ebx*/){
    monitor_initialize();
    // print("\n");

    // Convert values to string
    char* eax_buf;
    char* mb_magic_buf;
}