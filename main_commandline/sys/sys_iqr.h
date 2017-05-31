#ifndef _sys_iqr_h_
#define _sys_iqr_h_
#include "../platform_setup.h"

#ifndef ARDUINO_IDE
    #define millis  system_millis
#endif

extern uint32_t count_millis;

extern uint32_t system_millis();
extern void system_1_ms_iqr();

extern void serial_iqr();

#endif
