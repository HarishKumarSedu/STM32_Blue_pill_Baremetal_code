#include "stm32f10xx.h"
#include <stdint.h>


// int main(){
//             // Blue LED
//     RCC->AHBENR |=  BITSET(4);
//     GPIO->CRH |= (BITSET(20) | BITSHIFRIGHT(23,0x00));
//     GPIO->ODR |=  BITSET(13);
    
//     return 0 ;
// }

void wait() {
    // Do some NOPs for a while to pass some time.
    for (unsigned int i = 0; i < 2000000; ++i) {}
}

int main() {
    // Enable port C clock gate.
    *((volatile unsigned int *)0x40021018) |= (1 << 4);

    // Configure GPIO C pin 13 as output.
    *((volatile unsigned int *)0x40011004) = ((0x44444444 // The reset value
        & ~(0xfU << 20))  // Clear out the bits for pin 13
        |  (0x3U << 20)); // Set both MODE bits, leave CNF at 0

    while (1) {
        // Set the output bit.
        *((volatile unsigned int *)0x40011010) = (1U << 13);
        wait();
        // Reset it again.
        *((volatile unsigned int *)0x40011010) = (1U << 29);
        wait();
    }

    return 0;
}