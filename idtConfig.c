#include "keyboardIsr.h"
#include <stddef.h>
#include <stdint.h>

#define idtSize 256

struct entries {
  uint16_t offset2;
  uint16_t selector;
  uint8_t reserved;
  uint8_t type_attr;
  uint16_t offset1;
} __attribute__((packed));

struct entries idt[idtSize];

void set_idt_entry(int n, uint32_t isr_address, uint16_t selector,
                   uint8_t type_attr) {
  idt[n].offset1 = isr_address & 0xFFFF;
  idt[n].selector = selector;
  idt[n].reserved = 0;
  idt[n].type_attr = type_attr;
  idt[n].offset2 = (isr_address >> 16) & 0xFFFF;
}

void init_interrupts() {
  set_idt_entry(33, (uint32_t)keyboard_isr, 0x08, 0x8E);
}

/*
 * if actual, use these to enable/disable ints
 *
void enable_interrupts() { asm volatile("sti"); }

void disable_interrupts() { asm volatile("cli"); }
*/
