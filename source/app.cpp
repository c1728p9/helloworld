#include "mbed/mbed.h"

int i;

static void blinky(void) {
    static DigitalOut led1(LED1);
    static DigitalOut led2(LED2);
    static DigitalOut led3(LED3);
      
    led1 = !led1;
    led2 = !led2;
    led3 = !led3;
          
  //printf("hi # %x\n", i);
  i++;
  if (i >= 0xFFFF){
    i = 0;
  }
}

void app_start(int, char**) {
    i = 0;
    printf("hello world\n");
    minar::Scheduler::postCallback(blinky).period(minar::milliseconds(500));
}
