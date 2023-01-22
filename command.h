
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pico/mutex.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"

#include "console.h"

// access to externally defined variables
extern semaphore_t semCommand;
extern char commandLine[];

void commandProcessor ();