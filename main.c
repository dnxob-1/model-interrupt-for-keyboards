#include "idtConfig.h"
#include <stdint.h>
#include <stdio.h>

int are_interrupts_enabled() {
  // how you would actually check. not sure if it will work here since this is
  // compiled with no freestanding.
  uint64_t rflags;
  asm volatile("pushfq\n\t"
               "popq %0"
               : "=r"(rflags));

  return rflags & 0x200;
}

int main(void) {
  init_interrupts();

  if (are_interrupts_enabled()) {
    printf("ran\n");
  }

  return 0;
}
