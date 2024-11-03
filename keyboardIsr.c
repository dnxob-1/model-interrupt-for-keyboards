#include "io.h"
#include <stddef.h>
#include <stdint.h>

volatile uint8_t keycode = 0;

void keyboard_isr() {

  // read keycode from keyboard data port
  keycode = inb(0x60);

  // to pic if there is one.
  // outb(0x20, 0x20);
}
