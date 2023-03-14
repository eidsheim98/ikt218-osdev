
#include "system.h"

// Define entry point in asm to prevent C++ mangling
extern "C"{
    int kernel_main();
}

int kernel_main()
{
    // Initialise the screen (by clearing it)
    monitor_clear();
    // Write out a sample string
    monitor_write("Hello, world!");
    
    return 0;
}
