
#include "printing.h"
#include "gdt.h"
#include "idt.h"
#include "isr.h"


// Define entry point in asm to prevent C++ mangling
extern "C"{
    void kernel_main();
}
 
// Code from https://wiki.osdev.org/Bare_Bones#Writing_a_kernel_in_C

 
void kernel_main(void) 
{

	clear_terminal();
    

	// Create an IRQ handler for IRQ1
    register_irq_handler(IRQ1, [](registers_t*, void*){
		
        print("Yeah boiiii");
        // Read the scan code from keyboard
        unsigned char scan_code = inb(0x60);

        // Disable interrupts temporarily
        asm volatile("cli");
    }, NULL);



    // Print a message and enter an infinite loop to wait for interrupts
    print("Waiting...");
    while(1){};
}