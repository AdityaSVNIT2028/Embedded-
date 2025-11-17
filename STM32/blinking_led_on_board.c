// Write a program to toggle LED (LED 4 connected to pin PA5) of board at rate of 2.5 Hz for 3 times.
//  Wait for 1 sec. and then toggle at the rate of 1.6 Hz for 3 times. Repeat above steps repetitively.
#include "stm32g071xx.h"
void msdelay(uint32_t time);

int main(){
  RCC->IOPNER = 0X00000001; // THIS ENABLES THE CLK AND RESET FOR ALL THE RESPECTED REQUIREMENT 
  GPIOA -> MODER &= 0XFFFFF3FF;// PORT A PIN 5 IS O/P TYPE
  GPIOA->MODER |= 0X00000400;
  GPIOA->OTYPER &= 0XFFFFFFDF;// PUSH PULL TYPE
  GPIOA->PUPDR &= 0XFFFFFF3FF; // NO PUSH PULL 

  // NOW FOR BLINKING 
  while(1){
    uint32_t i =3;
    while(i--){
      GPIOA->BSRR = 0X00000020;
      msdelay(400);
      GPIOA->BSRR = 0X00200000;
      msdelay(400);
    }
    msdelay(1000);
    i = 3;
    while(i--){
      GPIOA->BSRR = 0X00000020;
      msdelay(600);
      GPIOA->BSRR = 0X00200000;
      msdelay(600);
    }
  }
}

void msdelay(uint32_t time){
  long int loops;
  loops = 8500*value*4;
  while(loops--){}
}
