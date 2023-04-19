extern "C" {
  extern void init_irq();
}
typedef struct registers
{
   u32int ds;                  // Data segment selector
   u32int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   u32int int_no, err_code;    // Interrupt number and error code (if applicable)
   u32int eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t; 

typedef void (*isr_t)(registers_t*, void*);


void register_irq_handler(int irq, isr_t handler, void* ctx);
void register_interrupt_handler(u8int  n, isr_t handler, void*);

