
#include "console.h"
#include "command.h"

// declare initialization method
void init ();

// declare semaphore to control command execution
semaphore_t semCommand;

// main runs on core0
int main () {
  init();
  // run console on core1
  multicore_launch_core1(console);
  // run command processor here on core0
  commandProcessor();
}

// initialize application
void init () {
  // initialize stdio
  stdio_init_all();
  stdio_flush();
  setbuf(stdout, NULL); // make sure character input is buffered
  // initialize command semaphore
  sem_init(&semCommand, 0, 1);
}