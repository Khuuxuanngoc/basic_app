#ifndef _sys_debug_h_
#define _sys_debug_h_
#include "../common/hardware_serial.h"

    #if defined(ARDUINO_IDE)
        #define sys_db(x)   Serial.print(x)
    #else
        #error "please choose platform for sys_debug kxn"
    #endif

    #define shell_db(x)     sys_db(x)
    #define app_db(x)       sys_db(x)

//    #define shell_db(x)
//    #define app_db(x)

#endif
