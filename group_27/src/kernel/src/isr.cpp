#include "common.h"
#include "isr.h"
#include "printing.h"

extern "C" {
    void isr_handler(registers_t regs) asm("isr_handler");
    void irq_handler(registers_t regs) asm("irq_handler");
}

struct interrupt_handler_t {
  int num;
  isr_t handler;
  void *data;
};

interrupt_handler_t interrupt_handlers[256];
interrupt_handler_t irq_handlers[16];

// ############################ ISR ############################

// Register ISR
void register_interrupt_handler(uint8_t n, isr_t handler, void* ctx)
{
    interrupt_handlers[n].handler = handler;
    interrupt_handlers[n].data = ctx;
}

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs)
{
    uint8_t int_no = regs.int_no & 0xFF;
    interrupt_handler_t intrpt = interrupt_handlers[int_no];
    if (intrpt.handler != 0)
    {
        intrpt.handler(&regs, intrpt.data);
    }
    else
    {
        for(;;);
    }
}


// ############################ IRQ ############################

// Array of IRQ handlers

void register_irq_handler(int irq, isr_t handler, void* ctx) {
  irq_handlers[irq].handler = handler;
  irq_handlers[irq].data = ctx;
}

// Gets called from the ASM interrupt handler in interrupt.asm
void irq_handler(registers_t regs)
{
   // Sends an EOI (end of interrupt) signal to the PICs.
   // If this interrupt involved the slave
   if (regs.int_no >= 40)
   {
       // Send reset signal to slave.
       outb(0xA0, 0x20);
   }
   // Send reset signal to master. (As well as slave, if necessary).
   outb(0x20, 0x20);

    interrupt_handler_t intrpt = irq_handlers[regs.int_no];
    if (intrpt.handler != 0)
    {
        intrpt.handler(&regs, intrpt.data);
    }
} 
