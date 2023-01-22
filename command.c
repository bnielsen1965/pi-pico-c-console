
#include "command.h"
#include "pico/bootrom.h"

// help message
const char * HELP = 
  "Pi Pico Basic Command Prompt - A simple 80 character command\n"
  "line buffer used to control the Pi Pico\n"
  "Commands:\n"
  "help - Display this help message\n"
  "bootrom - Reset and boot into BOOTSEL ROM\n";


// thread to process commands
void commandProcessor () {
  for (;;) {
    // block until console permits command processing
    sem_acquire_blocking(&semCommand);

    // continue if command line is empty
    if (0 == strlen(commandLine)) continue;
    // help command
    else if (0 == strcmp(commandLine, "help")) printf("%s", HELP);
    // bootrom command
    else if (0 == strcmp(commandLine, "bootrom")) reset_usb_boot(0, 0);
    // invalid input error
    else printf("Unknown command %s. Enter help command for help.\n", commandLine);
  }
}
